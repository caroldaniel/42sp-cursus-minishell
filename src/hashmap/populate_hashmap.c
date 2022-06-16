/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_hashmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:05:13 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 20:21:48 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	POPULATE_HASHMAP
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

void	populate_hashmap(char **variables)
{
	char		*key;
	char		*value;
	int			i;

	i = 0;
	while (variables[i])
	{
		key = get_key(variables[i]);
		value = get_value(variables[i]);
		hash_insert(key, value, ENV);
		i++;
	}
	if (!key_search("OLDPWD"))
	{
		key = ft_strdup("OLDPWD");
		value = NULL;
		hash_insert(key, value, ENV);				
	}
}
