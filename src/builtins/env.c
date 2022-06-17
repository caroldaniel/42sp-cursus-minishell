/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:41:13 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/17 00:17:49 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_list(t_hashlist *list);

/*	FT_ENV
**	------
**	DESCRIPTION
**	Prints the envp complete list of environment variables.
**	PARAMETERS
**	#1. The complete exec list of parameters.
**	RETURN VALUES
**	-
*/

int	ft_env(char **exec)
{
	t_hashtable	*table;
	size_t		i;

	i = 0;
	table = g_data.environ;
	if (!exec[1] || !*exec[1])
		while (i < table->size)
			print_list(table->list[i++]);
	else
		error(exec[1], -7, 127);
	return (0);
}

static void	print_list(t_hashlist *list)
{
	while (list)
	{
		if (list->att == ENV && list->value)
			printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
}
