/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:02:00 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/10 08:22:58 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//static char	*echo_element(char *element);

/*	ECHO
**	----
**	DESCRIPTION
**	Prints the parameter into the directory.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	echo(char *flags, char **parameter)
{
//	char	*content;
	char	*end;
	int		i;

	end = "\n";
	i = 1;
	if (flags && ft_strchr(flags, 'n'))
	{
		end = "\0";
		i = 2;
	}
	while (parameter[i])
	{
		if (i)
			printf(" ");
//		content = echo_element(parameter[i]);
		printf("%s", parameter[i]);
//		free(content);
		i++;
	}
	printf("%s", end);
}
/*
static char	*echo_element(char *element)
{
	char	*echo;

	if (ft_strncmp("$", element, 1))
		echo = ft_strdup(element);
	else
		echo = key_search(BOTH, &element[1]);
	return (echo);
}
*/