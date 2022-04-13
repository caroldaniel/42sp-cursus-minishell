/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:42:39 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/13 17:01:44 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"



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
