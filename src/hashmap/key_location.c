/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_location.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:57:30 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 15:10:46 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	KEY_LOCATION
**	------------
**	Checks which hashtable the variable is stored 
**	PARAMETERS
**	#1. The variable key 
**	RETURN VALUES
**	0 for Environment table, 1 for Local table, or -1 for not found.
*/

int	key_location(char *key)
{	
	t_hashtable	*table;
	t_hashlist	*tmp;
	int			index;

	table = g_data.environ;
	index = hash(key, table->size);
	tmp = table->list[index];
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(key)))
			return (tmp->att);
		tmp = tmp->next;
	}
	return (-1);
}
