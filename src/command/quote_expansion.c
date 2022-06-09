/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:04:44 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 12:03:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	variable_quote_expansion(t_tkn *tkn, int start, int *size);
static int	is_variable_expandable(char first_letter);
static char	*expand_variable(t_tkn *tkn, int *pos);

/*	QUOTE_EXPANSION
**	---------------
**	DESCRIPTION
**	It expands the token in which there are quotation marks (either "" or ''), 
**	as well as any possible variables ($VAR) within "".
**	PARAMETERS
**	#1. The token to expand.
**	RETURN VALUES
**	The expanded string, if appliable. NULL if no quotation was found.
*/

void	quote_expansion(t_tkn **tkn, int *pos, char quote)
{
	char	*prev;
	char	*next;
	char	*expansion;
	char	*result;
	int		size;

	prev = ft_strndup((*tkn)->token, *pos);
	(*pos)++;
	size = 0;
	while ((*tkn)->token[*pos + size] && (*tkn)->token[*pos + size] != quote)
	{
		if ((*tkn)->token[(*pos) + size] == '$' && quote == '\"')
			variable_quote_expansion(*tkn, *pos, &size);
		size++;
	}
	expansion = ft_strndup(&(*tkn)->token[*pos], size++);
	result = ft_strjoin(prev, expansion);
	free(prev);
	if (expansion)
		free(expansion);
	next = ft_strdup(&(*tkn)->token[*pos + size]);
	*pos = ft_strlen(result) - 1;
	swap_token(*tkn, ft_strjoin(result, next));
	free(result);
	free(next);
}

static void	variable_quote_expansion(t_tkn *tkn, int start, int *size)
{
	char	*prev;
	char	*expansion;
	char	*next;
	int		pos;

	pos = start + (*size);
	if (!is_variable_expandable(tkn->token[pos + 1]))
		return ;
	prev = ft_strndup(tkn->token, pos++);
	expansion = expand_variable(tkn, &pos);
	next = ft_strdup(&tkn->token[pos]);
	swap_token(tkn, ft_strnjoin(3, prev, expansion, next));
	*size = (*size) + ft_strlen(expansion) - 2;
	if (expansion)
		free(expansion);
	free(prev);
	free(next);
}

static int	is_variable_expandable(char first_letter)
{
	if (ft_isalnum(first_letter))
		return (1);
	if (first_letter == '?')
		return (1);
	return (0);
}

static char	*expand_variable(t_tkn *tkn, int *pos)
{
	char	*expansion;
	char	*key;
	int		i;

	i = 0;
	if (tkn->token[*pos] == '?')
		expansion = ft_itoa(g_data.exit_code);
	else if (ft_isdigit(tkn->token[*pos]))
		expansion = NULL;
	else
	{
		while (ft_isalnum(tkn->token[(*pos) + i]))
			i++;
		key = ft_strndup(&tkn->token[*pos], i--);
		expansion = ft_strdup(key_search(BOTH, key));
		free(key);
	}
	*pos = (*pos) + 1 + (i);
	return (expansion);
}
