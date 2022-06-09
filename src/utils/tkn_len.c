/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:52:13 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 12:29:57 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	TKN_LEN
**	-------
**	DESCRIPTION
**	This function will count the size of a t_tkn list. 
**	PARAMETERS
**	#1. The list to count from. 
**	RETURN VALUES
**	The int size.  
*/

size_t	tkn_len(t_tkn *tkn)
{
	size_t	len;

	len = 0;
	while (tkn)
	{
		len++;
		tkn = tkn->next;
	}
	return (len);
}
