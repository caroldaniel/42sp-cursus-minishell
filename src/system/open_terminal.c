/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:26:34 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/24 09:50:56 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_line(void);

void	open_terminal(void)
{
	change_input_signals();
	while (1)
	{
		read_line();
		tokenizer();
		clear_tokens();
	}
}

static void	read_line(void)
{
	char	*prompt;

	prompt = create_prompt();
	if (g_data.parser->input)
		free(g_data.parser->input);
	g_data.parser->input = readline(prompt);
	free(prompt);
	if (!g_data.parser->input)
		error("exit", 2, 0);
	add_history(g_data.parser->input);
}
