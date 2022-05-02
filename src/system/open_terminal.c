/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:26:34 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/02 09:45:29 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	execute_command(char *input);

void	open_terminal(void)
{
	char	*prompt;

	while (1)
	{
		change_signals();
		prompt = create_prompt();
		g_data.line->input = readline(prompt);
		free(prompt);
		add_history(g_data.line->input);
		// tokenizer(input);
		if (g_data.line->input)
			free(g_data.line->input);
	}
}

// static void	execute_command(char *input)
// {
// 	char	**command;
	
// 	command = ft_split(input, ' ');
// 	if (!command)
// 		return ;
// 	if (!ft_strncmp(command[0], "pwd", 4))
// 		pwd();
// 	if (!ft_strncmp(command[0], "exit", 5))
// 		exit(0);
// 	if (!ft_strncmp(command[0], "cd", 2))	
// 		cd(ft_strdup(command[1]));
// 	if (!ft_strncmp(command[0], "echo ", 5))
// 		echo(NULL, &command[1]);
// 	if (!ft_strncmp(command[0], "env", 4))
// 		print_hashmap(ENV);
// 	if (!ft_strncmp(command[0], "exit", 5))
// 		exit(0);
// }
