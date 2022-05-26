/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:20:53 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 11:22:48 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_part(const char *input, size_t size);

void	tokenizer(void)
{
	char	*input;
	size_t	i;
	size_t	prev;
	size_t	next;
	size_t	size;

	input = g_data.parser->input;
	i = 0;
	prev = i;
	next = i;
	size = 0;
	while (1)
	{
		if (is_new_token(input, i, prev))
			next = i;
		size = next - prev;
		if (size > 0)
			add_part(&input[prev], size);
		if (!input[i])
			break ;
		prev = next;
		i++;
	}
}

static void	add_part(const char *input, size_t size)
{
	t_tkn	*tkn;
	char	*token;

	while (*input == ' ')
	{
		size--;
		input++;
	}
	if (!size || !(*input))
		return ;
	token = ft_strndup(input, size);
	tkn = tkn_create(token);
	tkn_add_back(tkn);
}
