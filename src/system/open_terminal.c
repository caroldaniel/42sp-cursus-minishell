/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:26:34 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/28 11:21:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_command(char *input);

void	open_terminal(void)
{
	char	*input;
	char	*prompt;

	while (1)
	{
		prompt = create_prompt();
		change_signals();
		input = readline(prompt);
		free(prompt);
		add_history(input);
		execute_command(input);
		if (input)
			free(input);
	}
}

static void	execute_command(char *input)
{
	char	*path;

	if (!ft_strncmp(input, "pwd", 3))
	{
		path = pwd();
		printf("%s\n", path);
		free(path);
	}
}
