/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:26:34 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/07 09:19:01 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_line(void);
static int	parse_line(void);

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
//	token_print();
	exec_cmd_tab();
	return (1);
}
