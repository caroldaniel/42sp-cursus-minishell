/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:26:34 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 09:34:33 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_line(void);
static int	parse_line(void);

/*	OPEN_TERMINAL
**	-------------
**	DESCRIPTION
**	The open_terminal function is the core of the minishell program. It opens a
**	command prompt to the user in an infinite loop up until the program is
**	manually exited. The loop will first guarantee that the structs are cleared,
**	then it will open and read a line written by the user, parse it and execute
**	it, all of it using the main struct to pass data from one function to the
**	others.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	open_terminal(void)
{
	change_input_signals();
	while (1)
	{
		clear_parser();
		clear_cmd();
		read_line();
		if (!parse_line())
			continue ;
	}
}

static void	read_line(void)
{
	char	*prompt;

	prompt = create_prompt();
	g_data.parser = init_parser();
	g_data.parser->input = readline(prompt);
	free(prompt);
	if (!g_data.parser->input)
		error("exit", 2, 0);
	add_history(g_data.parser->input);
}

static int	parse_line(void)
{
	tokenizer();
	if (!syntax_analysis())
		return (0);
	command_table();
	token_print();
	exec_cmd_tab();
	return (1);
}
