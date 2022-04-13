/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:05:13 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/13 18:08:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	env_to_hashmap(char **list)
{
	int		i;
	char	*key;
	char	*value;
	int		index;

	i = 0;
	while (list[i])
	{
		key = get_key(list[i]);
		value = get_value(list[i]);
		index = hash(key);
		hash_insert(key, value, ENVIRON, index);
		free(key);
		free(value);
		i++;
	}
}
