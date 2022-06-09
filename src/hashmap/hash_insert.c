/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:12:35 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/08 16:56:18 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	hash_add_back(t_hashlist **list, char *key, char *value);

/*	HASH_INSERT
**	-----------
**	Inserts a new variable at the end of the hashtable's correct hashlist. 
**	PARAMETERS
**	#1. The hashtable in which to insert the new variable;
**	#2. The new variable. 
**	RETURN VALUES
**	-
*/

void	hash_insert(int type, char *key, char *value)
{
	t_hashtable	*table;
	int			index;

	table = g_data.vars[type];
	index = hash(key, table->size);
	hash_add_back(&(table->list[index]), key, value);
	table->count++;
}

static void	hash_add_back(t_hashlist **list, char *key, char *value)
{
	t_hashlist	*new;
	t_hashlist	*tmp;

	new = malloc(sizeof(t_hashlist));
	if (!new)
		error(NULL, 0, 12);
	new->key = key;
	new->value = value;
	new->next = NULL;
	tmp = *list;
	if (!tmp)
		*list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
