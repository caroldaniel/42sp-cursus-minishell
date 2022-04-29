/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:18:21 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/29 07:53:46 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(char *variable)
{
	char	*key;
	char	*value;
	int		location;

	key = get_key(variable);
	value = get_value(variable);
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
