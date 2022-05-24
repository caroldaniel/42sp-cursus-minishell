/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_pipe_and_or_if.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:05:19 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/24 09:53:11 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_pipe_and_or_if(int pos)
{
	int		*lexema;
	char	**token;

	lexema = g_data.parser->tokens->lexemas;
	token = g_data.parser->tokens->list;
	if (lexema[pos] == PIPE || lexema[pos] == AND_IF || lexema[pos] == OR_IF)
	{
		if (pos == 0 || !token[pos + 1])
		{
			error(token[pos], -3, 2);
			return (0);
		}
	}
	return (1);
}
