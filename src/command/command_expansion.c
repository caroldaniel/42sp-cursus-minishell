/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:23:12 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/22 09:03:57 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	token_expansion(t_tkn **tkn);
static void	expand_redirects(t_cmd *cmd);

/*	COMMAND_EXPANSION
**	-----------------
**	DESCRIPTION
**	This function will alterate the t_tkn list nodes in place according to
**	specific expansion rules of shell's grammar. The expansion rules include:
**	tilde expansion according to the HOME environment variable, variable
**	expansion according to the environment and local variables (prompted by '$')
**	and quotation expansion, both happening upon start and closing marks.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	command_expansion(void)
{
	t_cmd	*cmd;
	t_tkn	*tkn;

	cmd = g_data.cmd;
	while (cmd)
	{
		tkn = cmd->commands;
		while (tkn)
		{
			token_expansion(&tkn);
			tkn = tkn->next;
		}
		expand_redirects(cmd);
		cmd = cmd->next;
	}
}

static void	expand_redirects(t_cmd *cmd)
{
	t_tkn	*tkn;

	tkn = cmd->redirects;
	while (tkn)
	{
		if (ft_strncmp(tkn->token, "<<", 3))
		{
			tkn = tkn->next;
			token_expansion(&tkn);
		}
		else
			tkn = tkn->next;
		tkn = tkn->next;
	}
}

static void	token_expansion(t_tkn **tkn)
{
	int		pos;

	pos = 0;
	if ((*tkn)->token[pos] == '~')
		tilde_expansion(tkn, &pos);
	// if (ft_strchr((*tkn)->token, '*'))
	// 	wildcard_expansion(tkn, &pos);
	while ((*tkn)->token[pos])
	{	
		if ((*tkn)->token[pos] == '$')
			variable_expansion(tkn, &pos);
		else if ((*tkn)->token[pos] == '\'' || (*tkn)->token[pos] == '\"')
			quote_expansion(tkn, &pos, (*tkn)->token[pos]);
		pos++;
	}
}

void	swap_token(t_tkn *tkn, char	*new_token)
{
	free(tkn->token);
	tkn->token = new_token;
}
