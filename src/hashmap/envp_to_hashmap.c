/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_to_hashmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:05:13 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/14 10:44:06 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	envp_to_hashmap(t_hashtable **table, char **variables)
{
	int		i;

	i = 0;
	while (variables[i])
		hash_insert(table, variables[i++]);
}
