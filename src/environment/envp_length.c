/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:56:27 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/14 14:51:53 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	ENVP_LENGTH
**	-----------
**	DESCRIPTION
**	Gets the length of the environment variables' list. 
**	PARAMETERS
**	#1. The environment variables' list.
**	RETURN VALUES
**	The size_t number correspondent to the list's length.
*/

size_t	envp_length(char **envp)
{
	size_t	i;

	if (!envp)
		return (0);
	i = 0;
	while (envp[i])
		i++;
	return (i);
}
