/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:46:31 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/14 11:57:30 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1 && argv)
		error(1);
	g_data.envp = create_hashtable(envp);
	g_data.local = create_hashtable(NULL);

	// PRINT ENVIRONMENT LISTS - OK
	// size_t i = -1;
	
	// while (envp[++i])
	// 	printf("%s\n", envp[i]);

	// printf("\n\n");
	
	// t_hashlist	*list;
	
	// printf("There are %li environment variables available\n", g_data.envp->count);
	// i = -1;
	// while (++i < g_data.envp->size)
	// {
	// 	list = g_data.envp->list[i];
	// 	while (list)
	// 	{
	// 		printf("%s=%s in index %li\n", list->key, list->value, i);
	// 		list = list->next;
	// 	}
	// }
}
