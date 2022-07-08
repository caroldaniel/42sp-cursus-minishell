/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:59:21 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/08 13:38:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a new string, which is the result of 
*	the concatenation of ’s’ and the char ’c’.
*	PARAMETERS
*	#1. The prefix string.
*	#2. The suffix char.
*	RETURN VALUES
*	The new string. NULL if the allocation fails.
*/

char	*ft_appendchr(char const *s, char const c)
{
	char	*ccat;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	ccat = (char *)malloc((len + 2) * sizeof(char));
	if (!ccat)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ccat[i] = s[i];
		i++;
	}
	ccat[i++] = c;
	ccat[i] = '\0';
	return (ccat);
}
