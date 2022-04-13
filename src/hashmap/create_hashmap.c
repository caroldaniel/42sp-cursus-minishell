/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:43:28 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/13 16:17:05 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_hashtable	*create_hashtable(char **list)
{
	t_hashtable *table;
	size_t		list_len;

	table = malloc(sizeof(t_hashtable));
	if (!table)
		error(2);
	list_len = ft_listlen(list);
	if (!list_len)
		list_len = 50;
	table->list = create_table(list_len, list);
	table->size = list_len;
	return (table);
}

t_hashlist **create_table(size_t list_len, char **list)
{
	t_hashlist **table;
	int i;

	i = -1;
	table = malloc(sizeof(t_hashlist *) * list_len);
	if (!table)
		error(3);
	if (list)
		while (list[++i])
			printf("%s\n", list[i]);
	return (table);
}
