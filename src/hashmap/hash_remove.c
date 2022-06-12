/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:44:47 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/11 19:45:59 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	HASH_REMOVE
**	-----------
**	Removes a variable from the hashtable's correct hashlist. 
**	PARAMETERS
**	#1. The hashtable in which to remove the variable from;
**	#2. The variable's key to delete. 
**	RETURN VALUES
**	-
*/

void	hash_remove(int type, char *key)
{
	t_hashtable	*table;
	t_hashlist	*last;
	t_hashlist	*prev;
	t_hashlist	*tmp;

	table = g_data.vars[type];
	tmp = table->list[hash(key, table->size)];
	last = NULL;
	prev = NULL;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(key)))
		{
			if (!last)
				table->list[hash(key, table->size)] = tmp->next;
			else
			{
				last = tmp->next;
				prev->next = last;
			}
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			tmp = NULL;
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return ;
}
