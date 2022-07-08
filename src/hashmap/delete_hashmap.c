/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:11:50 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/02 21:59:09 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	list_delete(t_hashlist *node);

/*	DELETE_HASHMAP
**	--------------
**	Deletes the hashtable and all its nodes, guaranteeing that the linked lists
**	available are properly freed.
**	PARAMETERS
**	#1. The type of the hashtable to delete (Environment, Local or Both). 
**	RETURN VALUES
**	-
*/

void	delete_hashmap(void)
{
	t_hashtable	*table;
	size_t		i;

	i = 0;
	table = g_data.environ;
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
