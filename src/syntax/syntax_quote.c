/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:08:07 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/24 09:53:23 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_quote(int pos)
{
	char	**token;
	int		flag;
	int		i;

	token = g_data.parser->tokens->list;
	flag = -1;
	i = 0;
	if (!token[pos + 1])
	{
		while (token[pos][i])
		{
			if (flag == -1 && (token[pos][i] == '\"' || token[pos][i] == '\''))
				flag = i;
			if (flag != -1 && token[pos][i] == token[pos][flag])
				flag = -1;
			i++;
		}
		if (flag != -1)
		{
			error(NULL, -5, 2);
			return (0);
		}
	}
	return (1);
}
