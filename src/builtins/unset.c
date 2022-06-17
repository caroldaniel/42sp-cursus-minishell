/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:44:46 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/17 00:17:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	FT_UNSET
**	--------
**	DESCRIPTION
**	Deletes a variable from the environ list.
**	PARAMETERS
**	#1. The complete exec list of parameters.
**	RETURN VALUES
**	0 for sucess, 1 for error.
*/

int	ft_unset(char **exec)
{
	int		i;

	i = 0;
	while (exec[++i])
		hash_remove(exec[i]);
	return (0);
}
