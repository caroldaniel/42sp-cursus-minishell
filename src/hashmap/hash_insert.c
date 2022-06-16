/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:12:35 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 20:22:08 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	hash_add_back(t_hashlist **list, char *key, char *value, int att);

/*	HASH_INSERT
**	-----------
**	Inserts a new variable at the end of the hashtable's correct hashlist.
**	PARAMETERS
**	#1. The key of the new variable;
**	#2. The value of the new variable;
**	#3. The export attribute of the variable.
**	RETURN VALUES
**	-
*/

void	hash_insert(char *key, char *value, int att)
{
	t_hashtable	*table;
	int			index;

	table = g_data.environ;
	index = hash(key, table->size);
	hash_add_back(&(table->list[index]), key, value, att);
	table->count++;
	free(key);
	free(value);
}

static void	hash_add_back(t_hashlist **list, char *key, char *value, int att)
{
	t_hashlist	*new;
	t_hashlist	*tmp;

	new = malloc(sizeof(t_hashlist));
	if (!new)
		error(NULL, 0, 12);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->att = att;
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
