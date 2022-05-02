/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hashmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:43:28 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/28 14:00:52 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	CREATE_HASHMAP
**	----------------
**	DESCRIPTION
**	Takes a list of variables and put them into a hashtable. If list is NULL, 
**	returns a hashtable of 50 NULL positions. 
**	PARAMETERS
**	#1. A list of variables.
**	RETURN VALUES
**	The hashtable with the variables sorted into it.
*/

t_hashtable	*create_hashmap(char **variables)
{
	t_hashtable	*table;

	table = malloc(sizeof(t_hashtable));
	if (!table)
		error(NULL, 0, 12);
	table->size = envp_length(variables);
	if (!table->size)
		table->size = 50;
	table->count = 0;
	table->list = ft_calloc(sizeof(t_hashlist *), table->size);
	if (!table->list)
		error(NULL, 0, 12);
	return (table);
}
