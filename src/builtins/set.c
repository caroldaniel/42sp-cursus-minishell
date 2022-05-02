/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 08:10:30 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/29 12:02:53 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	SET
**	---
**	DESCRIPTION
**	Set a local variable. If the variable already exists in the local list,
**	it will substitute it. If it exists in the env list, it will then 
**	susbstitute it there. 
**	PARAMETERS
**	#1. The variable string.
**	RETURN VALUES
**	-
*/

void	set(char *key, char *value)
{
	int		location;

	location = key_location(key);
	if (location == -1)
		hash_insert(LOCAL, key, value);
	else if (location == ENV)
		hash_substitute(ENV, key, value);
	else
		hash_substitute(LOCAL, key, value);
}
