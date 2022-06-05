/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:23:12 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/05 20:41:58 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	token_expansion(t_tkn **tkn);
static void	expand_redirects(t_cmd *cmd);

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
	char	*token;
	int		pos;

	token = (*tkn)->token;
	pos = -1;
	if (token[++pos] == '~')
		tilde_expansion(tkn, &pos);
	while (token[pos])
	{	
		if (token[pos] == '$')
			variable_expansion(tkn, &pos);
		pos++;
	}
}

void	swap_token(t_tkn *tkn, char	*new_token)
{
	free(tkn->token);
	tkn->token = new_token;
}
