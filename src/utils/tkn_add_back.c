/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:00:38 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 12:27:58 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	TKN_ADD_BACK
**	------------
**	DESCRIPTION
**	Add the created t_tkn node to the back of a t_tkn list.  
**	PARAMETERS
**	#1. The t_tkn's list in which to add the node;
**	#2. The node to be added.
**	RETURN VALUES
**	-
*/

void	tkn_add_back(t_tkn **list, t_tkn *token)
{
	t_tkn	*tmp;

	tmp = *list;
	if (!tmp)
		(*list) = token;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = token;
	}
}
