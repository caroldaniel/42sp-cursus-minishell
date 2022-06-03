/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:00:38 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/01 19:50:52 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	TKN_REMOVE
**	-----------
**	Removes a token from the tkn struct. 
**	PARAMETERS
**	#1. The tkn list in which to remove the variable from;
**	#2. The token's string to delete. 
**	RETURN VALUES
**	-
*/

void	tkn_remove(t_tkn **list, char *token)
{
	t_tkn	*tmp;
	t_tkn	*last;

	tmp = *list;
	last = NULL;
	while (tmp)
	{
		if (!ft_strncmp(tmp->token, token, ft_strlen(token)))
		{
			if (!last)
				*list = tmp->next;
			else
				last->next = tmp->next;
			free(tmp->token);
			free(tmp);
		}
		last = tmp;
		tmp = tmp->next;
	}
}
