/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:29:23 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/04 15:42:09 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_in_quotes(const char *input, size_t index);
static int	is_part_of_last(char curr, char last);

int	is_new_token(const char *input, size_t index, size_t prev)
{
	if (!index || !input[index])
		return (1);
	if (is_in_quotes(input, index))
		return (0);
	if (ft_strchr(METACHARS, input[index]))
	{
		if (index - prev == 1)
			return (is_part_of_last(input[index], input[index - 1]));
		if (input[index] == ' ' && input[index - 1] == ' ')
			return (0);
		return (1);
	}
	if (index > 0 && ft_strchr(METACHARS, input[index - 1]))
		return (1);
	return (0);
}

static int	is_in_quotes(const char *input, size_t index)
{
	int		is_in;
	int		i;

	is_in = -1;
	i = 0;
	while (i < (int)index)
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			if (is_in == -1)
				is_in = (int)i;
			else if (is_in != -1 && input[is_in] == input[i])
				is_in = -1;
		}
		i++;
	}
	if (is_in != -1)
		return (1);
	return (0);
}

static int	is_part_of_last(char curr, char last)
{
	if (curr == '|' && last == '>')
		return (0);
	if (curr == '|' && last == '|')
		return (0);
	if (curr == '>' && last == '>')
		return (0);
	if (curr == '<' && last == '<')
		return (0);
	if (curr == '&' && last == '&')
		return (0);
	if (curr == ' ' && last == ' ')
		return (0);
	return (1);
}