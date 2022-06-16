/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_key_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:22:30 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 13:26:58 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	GET_KEY | GET_VALUE
**	-------------------
**	DESCRIPTION
**	Both functions work together to extract from a variable single string the
**	`key` (variable name) and `value` (variable content). 
**	PARAMETERS
**	#1. The full string variable.
**	RETURN VALUES
**	The key/value string.
*/

char	*get_key(char *variable)
{
	char	*key;
	int		i;

	if (!ft_strchr(variable, '='))
		return (NULL);
	i = 0;
	while (variable[i] != '=')
		i++;
	key = malloc(sizeof(char) * (++i));
	if (!key)
		error(NULL, -1, 12);
	ft_strlcpy(key, variable, i);
	return (key);
}

char	*get_value(char *variable)
{
	char	*value;
	int		i;

	if (!ft_strchr(variable, '='))
		return (NULL);
	i = 0;
	while (variable[i] != '=')
		i++;
	value = ft_strdup(&variable[++i]);
	return (value);
}
