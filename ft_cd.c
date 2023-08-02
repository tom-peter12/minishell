/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:54:42 by tpetros           #+#    #+#             */
/*   Updated: 2023/08/02 12:45:52 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static char    *extract_key(char *str)
{
	char    *res;
	size_t  len;

	len = 0;
	while (str[len] && str[len] != '=')
		len++;
	res = ft_substr(str, 0, len);
	return(res);
}

static char    *extract_value(char *str)
{
	char    *res;
	size_t  len;
	size_t  start;

	start = 0;
	while (str[start] && str[start] != '=')
		start++;
	start++;
	len = ft_strlen(str + start);
	res = ft_substr(str, start, len);
	return(res);
}

void	ft_del_enve(t_evar **head, char *str)
{
	t_evar	*temp;
	t_evar	*prev;

    if (!head || !*head || !str)
        return ;
    temp = *head;
	prev = NULL;
    if (temp != NULL && ft_strncmp(temp->key, str, ft_strlen(str)) == 0)
    {
        *head = temp->next;
        free(temp->key);
        free(temp->value);
        free(temp);
        return;
    }
    while (temp != NULL && ft_strncmp(temp->key, str, ft_strlen(str)) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return ;
    prev->next = temp->next;
    free(temp->key);
    free(temp->value);
    free(temp);
}

static t_evar  *new_evar(char  *str)
{
	t_evar  *newvar;

	newvar  = malloc(sizeof(t_evar));
	if(!newvar)
		return (NULL);
	newvar->key = extract_key(str);
	newvar->value = extract_value(str);
	newvar->next = NULL;
	return (newvar);
	
}

static void    add_back_env(t_evar **evar, t_evar *newvar)
{
	t_evar	*tmp;

	tmp = *evar;
	if (tmp == NULL)
	{
		*evar = newvar;
		return ;
	}
	if(evar && *evar && newvar)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newvar;
	}
	return ;
}


void	old_pwd(t_evar *env)
{
	t_evar	*tmp;
	char	oldpwd[PATH_MAX];

	tmp = env;
	getcwd(oldpwd, PATH_MAX);
	while (tmp)
	{
		if (ft_strncmp("OLDPWD", tmp->key, 6) == 0)
		{
			ft_del_enve(&env, "OLDPWD");
			add_back_env(&env, new_evar(ft_strjoin("OLDPWD=", oldpwd)));
			break ;
		}
		tmp = tmp->next;
	}
}

void	new_pwd(t_evar *env)
{
	t_evar	*tmp;
	char	newpwd[PATH_MAX];

	tmp = env;
	getcwd(newpwd, PATH_MAX);
	while (tmp)
	{
		if (ft_strncmp("PWD", tmp->key, 3) == 0)
		{
			ft_del_enve(&env, "PWD");
			add_back_env(&env, new_evar(ft_strjoin("PWD=", newpwd)));
			break ;
		}
		tmp = tmp->next;
	}
}

int	ft_cd(t_evar *env, t_cmd *cmd)
{
	t_evar	*tmp;
	int		code;

	tmp = env;
	code = EXIT_SUCCESS;
	if (cmd->cmdarg[2] != NULL)
		return (ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO), EXIT_FAILURE);
	old_pwd(env);
	if ((cmd->cmdarg[1]) == NULL || !ft_strncmp(cmd->cmdarg[1], "~", 1))
	{
		while (tmp)
		{
			if (ft_strcmp("HOME", tmp->key) == 0)
				chdir(tmp->value);
			tmp = tmp->next;
		}
	}
	else if (chdir(cmd->cmdarg[1]) != 0)
	{
		perror("minishell: cd");
		return (code = EXIT_FAILURE, code);
	}
	new_pwd(env);
	return (code);
}
