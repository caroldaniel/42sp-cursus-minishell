/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:47:05 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/01 21:54:27 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 20:21:35 by cado-car          #+#    #+#             */
/*   Updated: 2021/07/30 20:21:35 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	-
*	DESCRIPTION
*	The strisalpha() function tests for any string if all of its characters are
*	only alphanumerical. 
*	PARAMETERS
*	#1. The string to test.
*	RETURN VALUES
*	The strisalpha() function returns zero if the string tests any 
*	non-alphanumerical characters and returns one if it tests true.
*/

#include "libft.h"

int	ft_strisalnum(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isalnum(s[i]))
			return (0);
		i++;
	}
	return (1);
}
