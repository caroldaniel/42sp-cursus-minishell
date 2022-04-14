/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_to_hashmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:05:13 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/14 14:51:56 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	ENVP_TO_HASHMAP
**	---------------
**	DESCRIPTION
**	Takes the list of environment variables and, for each one of them, inserts 
**	them into the hash table passed.
**	PARAMETERS
**	#1. The hashtable in which to inser the variables;
**	#2. The list of variables passed
**	RETURN VALUES
**	-
*/

void	envp_to_hashmap(t_hashtable **table, char **variables)
{
	int		i;

	i = 0;
	while (variables[i])
		hash_insert(table, variables[i++]);
}
