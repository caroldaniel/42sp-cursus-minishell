/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:30:54 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 20:11:37 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	envp_create(void)
{
	t_hashtable	*table;
	t_hashlist	*list;
	char		**envp;
	size_t		i;
	int			j;
	
	table = g_data.environ;
	envp = malloc((table->count + 1) * sizeof(char *));
	if (!envp)
		error(NULL, 0, 12);
	i = 0;
	j = 0;
	while (i < table->size)
	{
		list = table->list[i];
		while (list)
		{
			if (list->att == ENV)
				envp[j++] = ft_strnjoin(3, list->key, "=", list->value);
			list = list->next;
		}
		i++;
	}
	envp[j] = NULL;
	g_data.environ->envp = envp;
}

void	envp_clear(void)
{
	char	**list;
	int		i;	
	
	list = g_data.environ->envp;
	i = -1;
	while (list[++i])
		free(list[i]);
	free(list);
	list = NULL;
}

void envp_swap(void)
{
	envp_clear();
	envp_create();
}