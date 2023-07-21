/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:11:56 by aandom            #+#    #+#             */
/*   Updated: 2023/07/01 15:52:04 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_minishell(char **env)
{
    t_data  *data;
    int     ex_code;
    
    data = malloc(sizeof(t_data));
    copy_env(data, env);
    // ft_env(data->envar);
    while (1)
    {
        data->input = readline(PROMPT);
        // ft_lexer(data);
        ft_parser(data);
        remove_quotes(&data->lexed);
        ft_expand(data);
        extract_command(data, data->lexed);
        // ex_code = execute(data);

        int i = 0;
        t_evar *tmp;
        t_evar  *evar;
        evar = data->envar;
        tmp = data->envar;
        // while (tmp != NULL)
        // {
            
        // //     // printf("pipe_out == %d ", tmp->pipeout);
        // //     // printf("\n");
        //     tmp = tmp->next;
        // }
        printf("\n");
        free(data->input);
    }
}

int main(int ac, char **av, char **env)
{
    (void) av;
    (void) env;
    if (ac != 1)
        return (0);
    // printf("\033[34m"); // Set color to blue
    // printf("⠀⢀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    // printf("⢀⣧⠞⠁⠀⢀⡹⠆⠠⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    // printf("⠀⡇⠀⢀⡴⠋⠀⠀⠀⠀⣨⠖⠀⠠⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    // printf("⠀⡇⢠⠎⠀⠀⠀⢀⡴⠛⠁⠀⠀⠀⠀⠀⠙⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    // printf("⠀⠸⣶⣾⣦⣄⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    // printf("⠀⢸⡿⣭⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣷⣶⣶⣦⡤⡀⠀⠀⠀⠀\n");
    // printf("⠀⠈⢿⣿⣽⢿⡄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜⢸⣿⣿⣿⣿⣯⡲⡄⠀⠀\n");
    // printf("⠀⠀⠈⢻⣿⣿⢿⣖⡄⣀⠀⠀⠀⠀⠀⠀⠀⡴⠁⣾⣿⣿⠿⠿⠇⠘⡆⠀\n");
    // printf("⠀⠀⠀⢸⣿⣿⣿⣿⣾⣿⣿⣦⣄⡀⠀⢀⠞⠀⣼⣿⣿⠟⠁⠀⠀⠀⠀⢸⠀\n");
    // printf("⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⡜⡌⢰⣿⣟⠇⠀⠄⠀⠀⠀⠀⢸⡇\n");
    // printf("⠀⠀⠀⠀⠹⣿⣷⣿⣻⣿⣿⣿⣿⣧⣧⠃⢾⡿⠙⠘⠘⠀⠀⠀⠀⠀⢸⡇\n");
    // printf("⠀⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣟⣛⠀⣽⣷⡀⢳⡀⠀⠀⠀⠀⠀⠀⢀⡎⠀\n");
    // printf("⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠿⣿⣿⣿⣿⣿⣿⣦⣍⠒⠂⠀⠀⠀⣠⠎⠀⠀\n");
    // printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠙⠛⠒⠒⠋⠁⠀⠀⠀\n");
    // printf("\033[0m"); // Reset color to default

    ft_minishell(env);
}