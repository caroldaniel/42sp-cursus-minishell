/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:23:12 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/03 14:38:56 by fausto           ###   ########.fr       */
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
		tkn = cmd->redirects;
        while (tkn)
        {
            if (ft_strncmp(tkn->token, "<<", 3))
            {
                tkn = tkn->next;
                token_expansion(tkn);
            }
            else
                tkn = tkn->next;
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
	new = single_quote_expansion(tkn->token);
	if (new)
		swap_command(tkn, new);
	new = double_quote_expansion(tkn->token);
	if (new)
		swap_command(tkn, new);
}

static void	swap_command(t_tkn *tkn, char *new)
{
	free(tkn->token);
	tkn->token = new;
}
