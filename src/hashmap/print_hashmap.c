/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hashmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:28:11 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/28 16:42:17 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_table(int type);
static void	print_list(t_hashlist *list);

static void	print_table(int type);

/*	PRINT_HASHMAP
**	-------------
**	Prints the hashmaps.
**	PARAMETERS
**	#1. The type of the hashmap to print. 
**	RETURN VALUES
**	-
*/

void	print_hashmap(int type)
{
	if (type == ENV || type == BOTH)
		print_table(ENV);
	if (type == LOCAL || type == BOTH)
		print_table(LOCAL);
}

static void	print_table(int type)
{
	t_hashtable	*table;
	size_t		i;

	i = 0;
	table = g_data.vars[type];
	if (type == ENV)
		printf("\nENVIRONMENT VARIABLES\n\n");
	else
		printf("\nLOCAL VARIABLES\n\n");
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
