/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:41:13 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/17 10:52:14 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_list(t_hashlist *list);

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
	int			ret;

	i = 0;
	table = g_data.environ;
	ret = 127;
	if (!key_search("PATH"))
		error(exec[0], -51, ret);
	else if (!exec[1] || !*exec[1])
		while (i < table->size)
			ret = print_list(table->list[i++]);
	else
		error(exec[1], -51, ret);
	return (ret);
}

static int	print_list(t_hashlist *list)
{
	while (list)
	{
		if (list->att == ENV && list->value)
			printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
	return (0);
}
