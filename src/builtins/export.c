/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:18:21 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/29 11:50:51 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	EXPORT
**	------
**	DESCRIPTION
**	Set an environment variable. If the variable already exists in the env list,
**	it will substitute it. If it exists in the local list, it will then remove
**	it from there and add it to the env. 
**	PARAMETERS
**	#1. The variable string.
**	RETURN VALUES
**	-
*/

void	export(char *key, char *value)
{
	int		location;

	location = key_location(key);
	if (location == -1)
		hash_insert(ENV, key, value);
	else if (location == ENV)
		hash_substitute(ENV, key, value);
	else
	{
		hash_remove(LOCAL, key);
		hash_insert(ENV, key, value);
	}
}
