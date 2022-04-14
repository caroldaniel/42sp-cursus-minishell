/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:02:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/14 13:09:28 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_envp_hash(char **envp)
{
	t_hashlist	*list;
	size_t		i;

	i = -1;
	while (envp[++i])
		printf("%s\n", envp[i]);
	printf("\n\n");
	printf("There are a total of %li variables\n", g_data.envp->count);
	i = -1;
	while (++i < g_data.envp->size)
	{
		list = g_data.envp->list[i];
		while (list)
		{
			printf("%s=%s in index %li\n", list->key, list->value, i);
			list = list->next;
		}
	}
}	
