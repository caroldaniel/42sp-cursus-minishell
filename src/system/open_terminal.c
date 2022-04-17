/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:26:34 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/16 21:30:05 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_current_folder(void);
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

char	*create_prompt(void)
{
	char	*name;
	char	*folder;
	char	*end;
	char	*prompt;

	name = ft_strdup("🐚🐚🐚 MINISHELL");
	folder = get_current_folder();
	end = ft_strdup(" $ ");
	prompt = ft_strnjoin(9, ESC_BOLD_CYAN, name, ESC_BOLD_WHITE, ":", 
		ESC_BOLD_BLUE, folder, ESC_BOLD_WHITE, end, ESC_RESET_COLOR);
	free(name);
	free(folder);
	free(end);
	return (prompt);
}

static char	*get_current_folder(void)
{
	char	*path;
	char	*folder;
	char	*result;

	path = pwd();
	folder = ft_strrchr(path, '/');
	result = ft_strdup(&folder[1]);
	free(path);
	return (result);
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
