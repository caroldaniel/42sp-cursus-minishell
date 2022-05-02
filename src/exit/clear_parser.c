/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:46:46 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/02 16:46:57 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear_tokens(void);

void	clear_parser(void)
{
	if (g_data.parser->input)
		free(g_data.parser->input);
	if (g_data.parser->tokens)
		clear_tokens();
	free(g_data.parser);
}

static void	clear_tokens(void)
{
	char	**list;
	int		i;

	list = g_data.parser->tokens->list;
	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
	free(g_data.parser->tokens);
}
