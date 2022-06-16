/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:47 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 20:24:54 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hash_export(char *key, int new_att)
{
	t_hashtable	*table;
	t_hashlist	*list;
	int			index;

	table = g_data.environ;
	index = hash(key, table->size);
	list = table->list[index];
	while (ft_strncmp(list->key, key, ft_strlen(key)))
		list = list->next;
	list->att = new_att;
	free(key);
}
