/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:20:53 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/24 17:05:10 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenizer(void)
{
	size_t	size;

	size = token_count(g_data.parser->input);
	g_data.parser->tokens = init_tokens();
	g_data.parser->tokens->count = size;
	g_data.parser->tokens->list = token_split(g_data.parser->input, size);
	g_data.parser->tokens->lexemas = \
		lexical_analysis(g_data.parser->tokens->list, size);
	if (syntax_analysis())
		printf("OK\n");
}
