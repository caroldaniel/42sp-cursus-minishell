/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:02:29 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 10:15:58 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_token(char *token);
static int	check_word(char *token);
static int	is_key_alnum(char *s, int stop);

int	lexical_analysis(char *token)
{
	int	lexema;

	lexema = check_token(token);
	return (lexema);
}

static int	check_token(char *token)
{
	if (ft_strlen(token) == 1)
	{
		if (token[0] == '|')
			return (PIPE);
		if (token[0] == '>')
			return (GREAT);
		if (token[0] == '<')
			return (LESS);
		if (token[0] == '&')
			return (AND);
	}
	if (ft_strlen(token) == 2)
	{
		if (token[0] == '|')
			return (OR_IF);
		if (token[0] == '>')
			return (DGREAT);
		if (token[0] == '<')
			return (DLESS);
		if (token[0] == '&')
			return (AND_IF);
	}
	return (check_word(token));
}

static int	check_word(char *token)
{
	size_t	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '=' && i != 0)
		{
			if (ft_isdigit(token[0]) || token[0] == '=')
				return (WORD);
			if (is_key_alnum(token, i))
				return (ASSIGN_WORD);
		}
		i++;
	}
	return (WORD);
}

static int	is_key_alnum(char *s, int stop)
{
	int	i;

	i = 0;
	while (i < stop)
	{
		if (!ft_isalnum(s[i]))
			return (0);
		i++;
	}
	return (1);
}
