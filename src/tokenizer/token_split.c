/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:23 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/03 20:53:33 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		create_split(char **result, const char *input);
static size_t	add_part(char **location, const char *input, size_t size);

char	**token_split(const char *input, size_t size)
{
	char	**result;

	result = ft_calloc((size + 1), sizeof(char *));
	if (!result)
		error(NULL, 0, 12);
	create_split(result, input);
	return (result);
}

static void	create_split(char **result, const char *input)
{
	size_t	i;
	size_t	c;
	size_t	prev;
	size_t	next;
	size_t	size;

	i = 0;
	c = 0;
	prev = i;
	next = i;
	while (1)
	{
		if (is_new_token(input, i))
			next = i;
		size = next - prev;
		if (size > 0)
			c += add_part(&result[c], &input[prev], size);
		if (!input[i])
			break ;
		prev = next;
		i++;
	}
	result[c] = NULL;
}

static size_t	add_part(char **location, const char *input, size_t size)
{
	size_t	i;

	i = 0;
	while (input[i] == ' ')
	{
		i++;
		size--;
	}
	if (!size || !input[i])
		return (0);
	*location = ft_calloc((size + 1), sizeof(char));
	if (!*location)
		error(NULL, 0, 12);
	ft_strlcpy(*location, &input[i], size + 1);
	return (1);
}

int	is_new_token(const char *input, size_t index)
{
	if (!index || !input[index])
		return (1);
	if (ft_strchr(METACHAR, input[index]) || input[index] == ' ')
	{
		if (input[index] == '|' && input[index - 1] == '>')
			return (0);
		if (input[index] == '|' && input[index - 1] == '|')
			return (0);
		if (input[index] == '>' && input[index - 1] == '>')
			return (0);
		if (input[index] == '<' && input[index - 1] == '<')
			return (0);
		if (input[index] == '&' && input[index - 1] == '&')
			return (0);
		if (input[index] == ' ' && input[index - 1] == ' ')
			return (0);
		return (1);
	}
	return (0);
}
