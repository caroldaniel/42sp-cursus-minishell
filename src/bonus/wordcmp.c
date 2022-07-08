/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordcmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:47:56 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/21 08:48:15 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		wordcmp(char *s1, char *s2)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (s1[i] && s2[i])
	{
		result = ft_tolower(s1[i]) - ft_tolower(s2[i]);
		if (result)
			break ;
		i++;
	}
	if (!result)
		result = ft_tolower(s1[i]) - ft_tolower(s2[i]);
	return (result);
}

