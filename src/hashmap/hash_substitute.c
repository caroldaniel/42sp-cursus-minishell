/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_substitute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:23:02 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/28 16:37:55 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	HASH_SUBSTITUTE
**	---------------
**	Substitute a new variable at the end of the hashtable's correct hashlist. 
**	PARAMETERS
**	#1. The hashtable ID from which to insert the new variable;
**	#2. The hashtable in which to insert the new variable;
**	#3. The variable's key. 
**	RETURN VALUES
**	-
*/

void	hash_substitute(int type, char *variable)
{
	t_hashtable	*table;
	char		*swap;
	char		*key;
	char		*value;
	int			index;

	key = get_key(variable);
	value = get_value(variable);
	table = g_data.vars[type];
	index = hash(key, table->size);
	while (ft_strncmp(table->list[index]->key, key, ft_strlen(key)))
		table->list[index] = table->list[index]->next;
	swap = table->list[index]->value;
	table->list[index]->value = value;
	free(key);
	free(swap);
}
