/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:06:36 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/23 10:02:51 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_and(int pos)
{
	int     *lexema;
    char    **token;
	
	lexema = g_data.parser->tokens->lexemas;
    token = g_data.parser->tokens->list;
	if (lexema[pos] == AND)
	{
		error(token[pos], -3, 2);
		return (0);
	}
	return (1);
}
