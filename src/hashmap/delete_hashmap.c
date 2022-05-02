/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:11:50 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/02 14:30:27 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	list_delete(t_hashlist *node);

/*	DELETE_HASHMAP
**	--------------
**	Deletes the hashtable and all its nodes.
**	PARAMETERS
**	#1. The type of the hashtable to delete. 
**	RETURN VALUES
**	-
*/

void	delete_hashmap(int type)
{
	t_hashtable	*table;
	size_t		i;

	i = 0;
	table = g_data.vars[type];
	while (i < table->size)
		list_delete(table->list[i++]);
	free(table->list);
	free(table);
}

static void	list_delete(t_hashlist *node)
{
	t_hashlist	*tmp;

	if (!node)
		return ;
	while (node)
	{
		tmp = node;
		node = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}
