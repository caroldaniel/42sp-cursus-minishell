/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 08:52:45 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/19 08:52:51 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	syntax_assignment(void);

/*	SYNTAX_ANALYSIS
**	---------------
**	DESCRIPTION
**	It verifies if the t_tkn's list order is correct according to the shell bash
**	grammar.  
**	PARAMETERS
**	-
**	RETURN VALUES
**	It returns 1 in case the syntax is correct, and 0 in case an error is found. 
*/

int	syntax_analysis(void)
{
	t_tkn	*token;
	t_tkn	*prev;
	int		pos;

	token = g_data.parser->tokens;
	prev = NULL;
	pos = 0;
	syntax_assignment();
	while (token)
	{
		if (!syntax_pipe_and_or_if(token, pos))
			return (0);
		else if (!syntax_io_redirect(token))
			return (0);
		else if (!syntax_and(token))
			return (0);
		else if (!syntax_parenthesis(token, prev))
			return (0);
		else if (!syntax_quote(token))
			return (0);
		prev = token;
		token = token->next;
		pos++;
	}
	return (1);
}

static void	syntax_assignment(void)
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
