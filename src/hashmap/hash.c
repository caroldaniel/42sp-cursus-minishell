/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:42:39 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/28 11:21:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	HASH
**	----
**	This is an implementation of Daniel J. Bernstein's (also known as djb2) hash
**	function. The idea is to initially set a variable called `hash` to the value
**	5381 and subsequently multiply it by 33 (or (hash << 5) + hash) and add the 
**	ASCII value of the current character to it, iterating over the entire word.
**	PARAMETERS
**	#1. The string `key` to be hashed;
**	#2. The size of the hashtable. 
**	RETURN VALUES
**	The modulo of hash by the size of the given hashtable.
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
