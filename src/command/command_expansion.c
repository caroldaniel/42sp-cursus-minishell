/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:23:12 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/03 09:26:13 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	token_expansion(t_tkn *tkn);
static void	swap_command(t_tkn *tkn, char *new);

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
			token_expansion(tkn);
			tkn = tkn->next;
		}
		cmd = cmd->next;
	}
}

static void	token_expansion(t_tkn *tkn)
{
	char	*new;

	new = tilde_expansion(tkn->token);
	if (new)
		swap_command(tkn, new);
	new = variable_expansion(tkn->token);
	if (new)
		swap_command(tkn, new);
}

static void	swap_command(t_tkn *tkn, char *new)
{
	free(tkn->token);
	tkn->token = new;
}
