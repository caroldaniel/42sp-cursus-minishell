/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:41:13 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/08 16:46:01 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_list(t_hashlist *list);

void	env(void)
{
	t_hashtable	*table;
	size_t		i;

	i = 0;
	table = g_data.vars[ENV];
	while (i < table->size)
		print_list(table->list[i++]);
}

static void	print_list(t_hashlist *list)
{
	while (list)
	{
		printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
}
