/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 08:10:30 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 18:51:31 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_single(char *key, char *value);

/*	SET
**	---
**	DESCRIPTION
**	Set a local variable. If the variable already exists in the local list,
**	it will substitute it. If it exists in the env list, it will then 
**	susbstitute it there. 
**	PARAMETERS
**	#1. The exec char **.
**	RETURN VALUES
**	-
*/

int	ft_set(char **exec)
{
	char	*key;
	char	*value;
	int		i;

	i = -1;
	while (exec[++i])
	{
		key = get_key(exec[i]);
		if (!key)
			continue ;
		value = get_value(exec[i]);
		set_single(key, value);
	}
	return (0);
}

static void	set_single(char *key, char *value)
{
	int		location;

	location = key_location(key);
	if (location == -1)
		hash_insert(key, value, LOCAL);
	else
		hash_substitute(key, value);
}
