/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_word_assignment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:07:18 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/04 11:15:57 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_word_assignment(void)
{
	t_tkn	*token;
	int		prev;

	token = g_data.parser->tokens;
	prev = -1;
	while (token)
	{
		if (token->lexema == ASSIGN_WORD)
			if (prev == WORD || (prev >= LESS && prev <= DGREAT))
				token->lexema = WORD;
		prev = token->lexema;
		token = token->next;
	}
}

int	is_assign_word(char *token)
{
	int	i;

	if (ft_strchr(token, '='))
	{
		i = 0;
		while (token[i] != '=')
		{
			if (!ft_isalnum(token[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
