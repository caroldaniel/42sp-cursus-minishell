/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:03:17 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 10:03:36 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	TKN_CREATE
**	----------
**	DESCRIPTION
**	This function will create a new t_tkn list node. 
**	PARAMETERS
**	#1. The token allocated string;
**	#2. The flag which indicates if the string will pass through the lexical 
**	analysis (0) or not (1).
**	RETURN VALUES
**	The allocated (malloc(3)) t_tkn node. 
*/

t_tkn	*tkn_create(char *token, int flag)
{
	t_tkn	*tkn;

	tkn = malloc(sizeof(t_tkn));
	if (!tkn)
		error(NULL, 0, 12);
	tkn->token = token;
	if (!flag)
		tkn->lexema = lexical_analysis(token);
	else
		tkn->lexema = WORD;
	tkn->next = NULL;
	return (tkn);
}
