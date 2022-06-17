/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_pipe_and_or_if.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:05:19 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 22:35:52 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	SYNTAX_PIPE_AND_OR_IF
**	---------------------
**	DESCRIPTION
**	Checks the correct grammar of pipe ('|'), and_if ('&&') and or_if ('||').  
**	PARAMETERS
**	#1. A t_tkn node;
**	#2. The index of the char in token's string.
**	RETURN VALUES
**	It returns 1 in case the syntax is correct, and 0 in case an error is found. 
*/

int	syntax_pipe_and_or_if(t_tkn *tkn, int pos)
{
	if (tkn->lexema == PIPE || tkn->lexema == AND_IF || tkn->lexema == OR_IF)
	{
		if (pos == 0 || !tkn->next)
		{
			error(tkn->token, -20, 2);
			return (0);
		}
	}
	return (1);
}
