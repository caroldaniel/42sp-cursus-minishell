/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:12:57 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/15 13:37:25 by cado-car         ###   ########.fr       */
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

char	*ft_strnjoin(int argn, ...)
{
	char	*result;
	char	*buf;
	char	*tmp;
	va_list	argl;
	int		i;

	if (argn == 0)
		return (NULL);
	va_start(argl, argn);
	result = NULL;
	i = -1;
	while (++i < argn)
	{
		buf = va_arg(argl, char *);
		if (i == 0)
			result = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(result, buf);
			free(result);
			result = tmp;
		}
	}
	va_end(argl);
	return (result);
}