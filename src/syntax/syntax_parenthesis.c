/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_parenthesis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 06:27:31 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/20 13:53:05 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_parenthesis(t_tkn *tkn, t_tkn *next);
static int	is_parenthesis_closed(void);

int	syntax_parenthesis(t_tkn *tkn, t_tkn *prev)
{
	if (tkn->lexema != PARENTHESIS)
		return (1);
	if (!prev && *tkn->token == ')')
	{
		error(tkn->token, -20, 2);
		return (0);
	}
	if (prev && (prev->lexema == AND_IF || prev->lexema == OR_IF || \
		prev->lexema == PIPE) && *tkn->token == ')')
	{
		error(tkn->token, -20, 2);
		return (0);
	}
	if (prev && (prev->lexema == ASSIGN_WORD || prev->lexema == WORD) && \
		tkn->token[0] == '(')
	{
		if (tkn->next)
			error(tkn->next->token, -20, 2);
		else
			error(NULL, -21, 2);
		return (0);
	}
	return (check_parenthesis(tkn, tkn->next));
}

static int	check_parenthesis(t_tkn *tkn, t_tkn *next)
{	
	if (!next && tkn->token[0] == '(')
	{
		error(NULL, -21, 2);
		return (0);
	}
	if (next && (next->lexema == AND_IF || next->lexema == OR_IF || \
		next->lexema == PIPE) && *tkn->token == '(')
	{
		error(tkn->token, -20, 2);
		return (0);
	}
	return (is_parenthesis_closed());
}

static int	is_parenthesis_closed(void)
{
	t_tkn	*tkn;
	int		count_open;
	int		count_close;

	tkn = g_data.parser->tokens;
	count_open = 0;
	count_close = 0;
	while (tkn)
	{
		if (tkn->lexema == PARENTHESIS)
		{
			if (*tkn->token == '(')
				count_open++;
			else if (*tkn->token == ')')
				count_close++;
		}
		tkn = tkn->next;
	}
	if (count_open == count_close)
		return (1);
	else if (count_open > count_close)
		error(NULL, -23, 2);
	else
		error(")", -20, 2);
	return (0);
}
