/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:06:36 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 10:14:15 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	SYNTAX_AND
**	----------
**	DESCRIPTION
**	Checks the correct grammar of the AND symbol ('&').  
**	PARAMETERS
**	#1. A t_tkn node.
**	RETURN VALUES
**	It returns 1 in case the syntax is correct, and 0 in case an error is found. 
*/

int	syntax_and(t_tkn *tkn)
{
	if (tkn->lexema == AND)
	{
		error(tkn->token, -3, 2);
		return (0);
	}
	return (1);
}
