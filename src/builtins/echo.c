/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:02:00 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 16:34:28 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	FT_ECHO
**	-------
**	DESCRIPTION
**	Prints the parameter into the directory.
**	PARAMETERS
**	#1. The complete exec list of parameters.
**	RETURN VALUES
**	0 for sucess, 1 for error.
*/

int	ft_echo(char **exec)
{
	char	*flag;
	int	i;
	
	flag = NULL;
	i = 1;
	if (exec[i] && *exec[i] == '-')
		flag = &exec[i++][1];
	while (exec[i])
	{
		printf("%s", exec[i++]);
		if (exec[i])
			printf(" ");
	}
	if (ft_strncmp(flag, "n\0", 2))
		printf("\n");
	return (0);
}
