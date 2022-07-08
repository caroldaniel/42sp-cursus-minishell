/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:12:57 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/08 13:44:37 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	-
*	DESCRIPTION
*	The ft_strnjoin() is a variadic function that allows the user to concatenate
*	how many strings they may want. The first argument passed must be the number
*	of arguments to be passed, followed by the strings to concatenate. The user
*	must pass the exact number of arguments, otherwise the function will most
*	likely segfault. 
*	PARAMETERS
*	#1. The number of strings;
*	... The variadic number of strings to concatenate. 
*	RETURN VALUES
*	The final concatenated string. 
*/

#include "libft.h"

static void	join_args(int argn, va_list argl, char **result);

char	*ft_strnjoin(int argn, ...)
{
	char	*result;
	va_list	argl;

	if (argn == 0)
		return (NULL);
	va_start(argl, argn);
	result = NULL;
	join_args(argn, argl, &result);
	va_end(argl);
	return (result);
}

static void	join_args(int argn, va_list argl, char **result)
{
	char	*buf;
	char	*tmp;
	int		i;

	i = -1;
	while (++i < argn)
	{
		buf = va_arg(argl, char *);
		if (i == 0)
			*result = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(*result, buf);
			if (*result)
				free(*result);
			*result = tmp;
		}
	}
}
