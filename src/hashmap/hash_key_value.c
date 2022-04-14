/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_key_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:42:39 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/14 13:09:28 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_key(char *variable)
{
	char	*key;
	int		i;

	i = 0;
	while (variable[i] != '=')
		i++;
	key = malloc(sizeof(char) * (++i));
	if (!key)
		error(4);
	ft_strlcpy(key, variable, i);
	return (key);
}

char	*get_value(char *variable)
{
	char	*value;
	int		i;

	i = 0;
	while (variable[i] != '=')
		i++;
	value = ft_strdup(&variable[++i]);
	return (value);
}

/*
** This is the implementation of Daniel J. Bernstein's (also known as djb2) hash
** function. The idea is to initially set a variable called `hash` to the value
** 5381 and subsequently multiply it by 33 (or (hash << 5) + hash) and add the 
** ASCII value of the current character to it, iterating over the entire word.
** The return hash number must be the modulo of hash by the size of the given
** hashtable.
*/

int	hash(char *key, size_t size)
{
	unsigned long int	hash;
	size_t				i;

	hash = 5381;
	i = 0;
	while (key && key[i])
	{
		hash = ((hash << 5) + hash) + key[i];
		i++;
	}
	return (hash % size);
}
