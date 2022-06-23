/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:50:11 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/20 13:54:00 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numberic(char *param);

/*	FT_EXIT
**	-------
**	DESCRIPTION
**	Exits minishell.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

int	ft_exit(char **exec)
{
	int	ret;

	ret = 0;
	if (exec[1] && exec[2])
	{
		error("exit", -4, 1);
		return (1);
	}
	if (exec[1] && is_numberic(exec[1]))
	{
		ret = ft_atoi(exec[1]);
		if (ret < 0 || ret > 255)
			ret = 128;
	}
	error("exit", 1, ret);
	return (0);
}

static int	is_numberic(char *param)
{
	int	i;

	i = -1;
	while (param[++i])
	{
		if (!ft_isdigit(param[i]) && param[i] != '+' && param[i] != '-')
			return (0);
	}
	return (1);
}
