/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:05:44 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/23 10:21:13 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_io_redirect(int pos)
{
	int     *lexema;
    char    **token;
	
	lexema = g_data.parser->tokens->lexemas;
    token = g_data.parser->tokens->list;
	if (lexema[pos] == LESS || lexema[pos] == DLESS || lexema[pos] == GREAT || \
		lexema[pos] == DGREAT)
	{
		if (!token[pos + 1])
		{
			error(NULL, -4, 2);
			return (0);	
		}
		else if (lexema[pos + 1] != WORD && lexema[pos + 1] != ASSIGNMENT_WORD)
		{
			error(token[pos + 1], -3, 2);
			return (0);	
		}	
	}
	return (1);	
}
