/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:12:35 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/14 14:54:14 by cado-car         ###   ########.fr       */
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

void	hash_insert(t_hashtable **table, char *variable)
{
	char	*key;
	char	*value;
	int		index;

	key = get_key(variable);
	value = get_value(variable);
	index = hash(key, (*table)->size);
	hash_add_back(&((*table)->list[index]), key, value);
	(*table)->count++;
}

static void	hash_add_back(t_hashlist **list, char *key, char *value)
{
	t_hashlist	*new;
	t_hashlist	*tmp;

	new = malloc(sizeof(t_hashlist));
	if (!new)
		error(5);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
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
