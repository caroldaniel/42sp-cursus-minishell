/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:03:43 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/22 12:01:12 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_wildcard(t_tkn **tkn, int *pos);

void	wildcard_expansion(t_tkn **tkn, int *pos)
{
	int	i;
	int	is_in;

	i = 0;
	is_in = -1;
	while ((*tkn)->token[i] && (*tkn)->token[i] != '/')
	{
		if ((*tkn)->token[i] == '\"' || (*tkn)->token[i] == '\'')
		{
			if (is_in == -1)
				is_in = i;
			if (is_in > -1 && is_in == (*tkn)->token[i])
				is_in = -1;
		}
		if ((*tkn)->token[i] == '*')
			break ;
		i++;
	}
	if ((*tkn)->token[i] == '*' && is_in == -1)
		expand_wildcard(tkn, &pos);
}

static void	expand_wildcard(t_tkn **tkn, int *pos)
{
	int		i;
	char	*prev;
	t_tkn	*curr;

	i = 0;
	while ((*tkn)->token[*pos])
	{
		while ((*tkn)->token[*pos] != '*')
		{	
			if ((*tkn)->token[*pos] == '$')
				variable_expansion(tkn, &(*pos));
			else if ((*tkn)->token[*pos] == '\'' || (*tkn)->token[*pos] == '\"')
				quote_expansion(tkn, &(*pos), (*tkn)->token[*pos]);
			(*pos)++;
		}
	}
}

static void expand_others(t_tkn **tkn)
{
	int	pos;

	pos = 0;
	if (!*tkn)
		return ;
	while ((*tkn)->token[pos])
	{	
		if ((*tkn)->token[pos] == '$')
			variable_expansion(tkn, &pos);
		else if ((*tkn)->token[pos] == '\'' || (*tkn)->token[pos] == '\"')
			quote_expansion(tkn, &pos, (*tkn)->token[pos]);
		pos++;
	}
}
