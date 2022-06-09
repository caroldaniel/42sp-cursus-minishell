/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:51:16 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 12:28:54 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	TKN_DUP
**	-------
**	DESCRIPTION
**	This function will duplicate a t_tkn node with next pointer to NULL. 
**	PARAMETERS
**	#1. The original token;
**	RETURN VALUES
**	The allocated (malloc(3)) t_tkn duplicated node.
*/

t_tkn	*tkn_dup(t_tkn *original)
{
	t_tkn	*tkn;

	tkn = malloc(sizeof(t_tkn));
	if (!tkn)
		error(NULL, 0, 12);
	tkn->token = ft_strdup(original->token);
	tkn->lexema = original->lexema;
	tkn->next = NULL;
	return (tkn);
}
