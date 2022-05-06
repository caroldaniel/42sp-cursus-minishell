/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:17:06 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/06 08:25:00 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	is_new_part(const char *input, size_t size);

size_t	token_count(const char *input)
{
	size_t	i;
	size_t	prev;
	size_t	next;
	size_t	size;
	size_t	counter;

	i = 0;
	counter = 0;
	prev = i;
	next = i;
	size = 0;
	while (1)
	{
		if (is_new_token(input, i, prev))
			next = i;
		size = next - prev;
		if (size > 0)
			counter += is_new_part(&input[prev], size);
		if (!input[i])
			break ;
		prev = next;
		i++;
	}
	return (counter);
}

static size_t	is_new_part(const char *input, size_t size)
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
	return (1);
}
