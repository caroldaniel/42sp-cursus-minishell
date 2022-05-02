/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:49:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/29 11:37:21 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*key_search_list(int type, char *key);

/*	KEY_SEARCH
**	----------
**	Searches for the value of a given key in a specific hashtable. 
**	PARAMETERS
**	#1. The hashtable to search in,
**	#2. The variable key .
**	RETURN VALUES
**	The value string.
*/

char	*key_search(int type, char *key)
{
	char	*value;

	if (type == ENV || type == BOTH)
		value = key_search_list(ENV, key);
	if (!value && (type == LOCAL || type == BOTH))
		value = key_search_list(LOCAL, key);
	return (value);
}

static char	*key_search_list(int type, char *key)
{
	t_hashtable	*table;
	t_hashlist	*tmp;
	int			index;

	table = g_data.vars[type];
	index = hash(key, table->size);
	tmp = table->list[index];
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(key)))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
