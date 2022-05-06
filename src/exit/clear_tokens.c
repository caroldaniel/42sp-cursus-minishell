/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:25:54 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/06 10:12:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_tokens(void)
{
	char	**list;
	int		*lexemas;
	int		i;

	list = g_data.parser->tokens->list;
	lexemas = g_data.parser->tokens->lexemas;
	i = -1;
	if (list)
	{
		while (list[++i])
			free(list[i]);
		free(list);
	}
	if (lexemas)
		free(lexemas);
	free(g_data.parser->tokens);
}
