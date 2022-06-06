/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:26:34 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/06 18:33:39 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_line(void);
static int	parse_line(void);
static void	execute_command(void);

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
		execute_command();
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
	return (1);
}

static void	execute_command(void)
{
	printf("Executed!\n");
}


