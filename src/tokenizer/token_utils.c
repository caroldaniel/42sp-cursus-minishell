/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:29:23 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 12:36:28 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_in_quotes(const char *input, size_t index);
static int	is_part_of_last(char curr, char last);

/*	IS_NEW_TOKEN
**	------------
**	DESCRIPTION
**	This is a function that will identify if the current char from the input
**	reading is a new token to be split. 
**	PARAMETERS
**	#1. The input original string;
**	#2. The current char index in the input string;
**	#3. The previous char index in the input string.
**	RETURN VALUES
**	It returns 1 in case of new token found, and 0 in case of not.
*/

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
