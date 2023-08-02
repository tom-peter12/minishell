/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:26:14 by tpetros           #+#    #+#             */
/*   Updated: 2023/08/02 12:46:45 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	PRESENT_WORKING_DIR[PATH_MAX];

	if (getcwd(PRESENT_WORKING_DIR, PATH_MAX))
	{
		printf("%s\n", PRESENT_WORKING_DIR);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}
