/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:18:21 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/04 11:17:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_single(char *key, char *value);
static void	print_exported(void);
static int	is_valid_key(char *key);

/*	FT_EXPORT
**	---------
**	DESCRIPTION
**	Sets environment variables. If a variable already exists in the env list,
**	it will substitute it. If it exists in the local list, it will then remove
**	it from there and add it to the env. 
**	PARAMETERS
**	#1. The complete exec list of parameters.
**	RETURN VALUES
**	0 for sucess, 1 for error.
*/

int	ft_export(char **exec)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	if (!exec[1] || !*exec[1])
		print_exported();
	while (exec[++i])
	{
		key = get_key(exec[i]);
		if (!key)
			key = ft_strdup(exec[i]);
		if (!is_valid_key(key))
		{
			error(key, -6, 1);
			free(key);
		}
		else
		{
			value = get_value(exec[i]);
			export_single(key, value);
		}
	}
	return (0);
}

static void	export_single(char *key, char *value)
{
	int	location;

	location = key_location(key);
	if (location == -1)
		hash_insert(key, value, ENV);
	else if (location == ENV && value)
		hash_substitute(key, value);
	else if (location == LOCAL)
		hash_export(key, ENV);
}

static void	print_exported(void)
{
	t_hashlist	**list;
	t_hashlist	*node;
	size_t		i;

	list = g_data.environ->list;
	i = 0;
	while (i < g_data.environ->size)
	{
		node = list[i];
		while (node)
		{
			if (node->att == ENV)
			{
				if (!node->value)
					printf("declare -x %s\n", node->key);
				else
					printf("declare -x %s=\"%s\"\n", node->key, node->value);
			}
			node = node->next;
		}
		i++;
	}
}

static int	is_valid_key(char *key)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (!ft_isalnum(key[i]))
			return (0);
		i++;
	}
	return (1);
}
