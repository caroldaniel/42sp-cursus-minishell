/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:05:44 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/17 08:54:49 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	SYNTAX_IO_REDIRECT
**	------------------
**	DESCRIPTION
**	Checks the correct grammar of redirect symbols ('>', '>>', '<' and '<<').  
**	PARAMETERS
**	#1. A t_tkn node.
**	RETURN VALUES
**	It returns 1 in case the syntax is correct, and 0 in case an error is found. 
*/

int	syntax_io_redirect(t_tkn *tkn)
{
	if (tkn->lexema == LESS || tkn->lexema == DLESS || tkn->lexema == GREAT || \
		tkn->lexema == DGREAT)
	{
		if (!tkn->next)
		{
			error(NULL, -21, 2);
			return (0);
		}
		else if (tkn->next->lexema != WORD && tkn->next->lexema != ASSIGN_WORD)
		{
			error(tkn->next->token, -20, 2);
			return (0);
		}
	}
	return (1);
}
