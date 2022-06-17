/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:30:54 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 22:30:44 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	ENVP_CREATE
**	-----------
**	DESCRIPTION
**	This function will malloc(3) and fill in a list of strings with all of the
**	exportabled environment variables, in order to be further called by execve.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

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

/*	ENVP_CLEAR
**	----------
**	DESCRIPTION
**	This function will free all memory allocated in the list of environment 
**	variables on the global struct.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

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

/*	ENVP_SWAP
**	---------
**	DESCRIPTION
**	This function will free all memory allocated in the list of environment 
**	variables on the global struct, and then proceed to reallocate a new list
**	with the current set of variables.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void envp_swap(void)
{
	envp_clear();
	envp_create();
}
