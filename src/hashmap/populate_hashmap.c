/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_hashmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:05:13 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/28 15:16:29 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	populate_hashmap
**	----------------
**	DESCRIPTION
**	Takes the list of environment variables and, for each one of them, inserts 
**	them into the hash table passed.
**	PARAMETERS
**	#1. The type of table to populate,
**	#2. The list of variables passed.
**	RETURN VALUES
**	-
*/

void	populate_hashmap(int type, char **variables)
{
	int			i;

	i = -1;
	while (variables[++i])
		hash_insert(type, variables[i]);
}
