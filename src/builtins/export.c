/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:18:21 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/28 16:41:53 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(char *variable)
{
	char	*key;
	int		location;

	key = get_key(variable);
	location = key_location(key);
	if (location == -1)
		hash_insert(ENV, variable);
	else if (location == ENV)
		hash_substitute(ENV, variable);
	else
	{
		hash_remove(LOCAL, key);
		hash_insert(ENV, variable);
	}
	free(key);
}
