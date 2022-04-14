/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:43:28 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/14 10:36:01 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_hashtable	*create_hashtable(char **variables)
{
	t_hashtable	*table;

	table = malloc(sizeof(t_hashtable));
	if (!table)
		error(2);
	table->size = ft_listlen(variables);
	if (!table->size)
		table->size = 50;
	table->count = 0;
	table->list = ft_calloc(sizeof(t_hashlist *), table->size);
	if (!table->list)
		error(3);
	if (variables)
		envp_to_hashmap(&table, variables);
	return (table);
}
