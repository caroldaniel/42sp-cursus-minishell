/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:49:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/16 17:01:51 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*hash_search(t_hashtable *table, char *key)
{
	int			index;
	t_hashlist	*tmp;

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
