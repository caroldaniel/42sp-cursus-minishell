/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:20:53 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/02 16:49:05 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	count_tokens(char	*input);
static size_t	metachar_skip(char	*input);
static size_t	quote_skip(char	*input, char c);

void	tokenizer(void)
{
	g_data.parser->tokens = get_tokens();
}

t_tokens	*get_tokens(void)
{
	t_tokens	*tokens;

	tokens = init_tokens();
	tokens->count = count_tokens(g_data.parser->input);
	return (tokens);
}

static size_t	count_tokens(char	*input)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		while (input[i] == ' ')
			i++;
		if (input[i])
		{
			if (ft_strchr(METACHARS, input[i]))
				i += metachar_skip(&input[i]);
			else
			{
				while (!ft_strchr(METACHARS, input[i]) || input[i] != ' ')
				{
					if (input[i] == '\'' || input[i] == '\"')
						i += quote_skip(&input[i], input[i]);
					else
						i++;
				}
			}
			count++;
		}
	}
	return (count);
}

static size_t	metachar_skip(char	*input)
{
	size_t	i;

	i = 0;
	if (input[i] == '|')
		i++;
	else if (input[i] == '<')
	{
		i++;
		if (input[i] == '<')
			i++;
	}
	else if (input[i] == '>')
	{
		i++;
		if (input[i] == '>')
			i++;
		if (input[i] == '|')
			i++;
	}
	return (i);
}

static size_t	quote_skip(char	*input, char c)
{
	size_t	i;

	i = 0;
	while (input[i] != c)
	{
		if (!input[i])
			error(NULL, 3, 1);
		i++;
	}
	i++;
	return (i);
}
