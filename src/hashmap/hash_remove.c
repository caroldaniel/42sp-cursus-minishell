/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:44:47 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/17 00:18:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_node(t_hashlist *curr);

/*	HASH_REMOVE
**	-----------
**	Removes a variable from the hashtable's correct hashlist. 
**	PARAMETERS
**	#1. The hashtable in which to remove the variable from;
**	#2. The variable's key to delete. 
**	RETURN VALUES
**	-
*/

void	hash_remove(char *key)
{
	t_hashlist	*curr;
	t_hashlist	*prev;
	int			index;

	index = hash(key, g_data.environ->size);
	prev = NULL;
	curr = g_data.environ->list[index];
	while (curr)
	{
		if (!ft_strncmp(curr->key, key, ft_strlen(key) + 1))
		{
			if (!prev)
				g_data.environ->list[index] = curr->next;
			else
				prev->next = curr->next;
			free_node(curr);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}

static void	free_node(t_hashlist *curr)
{
	free(curr->key);
	free(curr->value);
	free(curr);
	curr = NULL;
}
