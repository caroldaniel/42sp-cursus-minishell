/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:02:29 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/06 10:12:23 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_token(char *token);
static int	check_word(char *token);

int	*lexical_analysis(char **token, int size)
{
	int	*lexemas;
	int	i;

	lexemas = malloc(size * sizeof(int));
	if (!lexemas)
		error(NULL, 0, 12);
	i = -1;
	while (token[++i])
		lexemas[i] = check_token(token[i]);
	return (lexemas);
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
				return (ERROR);
			return (ASSIGNMENT_WORD);
		}
		i++;
	}
	return (WORD);
}
