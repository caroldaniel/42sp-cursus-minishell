/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:50:11 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/17 00:17:11 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	FT_EXIT
**	-------
**	DESCRIPTION
**	Exits minishell.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	ft_exit(void)
{
	error("exit", 1, 0);
}
