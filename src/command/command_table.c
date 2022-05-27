/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:12:29 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/27 09:53:35 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cmd_populate(t_cmd **cmd, t_tkn **list, int *prev);
static int	is_redirect(int prev, int cur);

void	command_table(void)
{
	t_cmd	*cmd_node;
	t_tkn	*list;
	int		prev;

	list = g_data.parser->tokens;
	prev = -1;
	while (list)
	{
		cmd_node = cmd_create();
		cmd_populate(&cmd_node, &list, &prev);
		cmd_add_back(cmd_node);
	}
	return ;
}

static void	cmd_populate(t_cmd **cmd, t_tkn **list, int *prev)
{
	t_tkn	*destiny;

	while (*list && (*list)->lexema < PIPE)
	{
		destiny = (*cmd)->commands;	
		if (is_redirect(*prev, (*list)->lexema))
			destiny = (*cmd)->redirects;
		tkn_add_back(&destiny, tkn_dup(*list));
		(*prev) = (*list)->lexema;
		(*list) = (*list)->next;
	}
	if (*list)
	{
		(*cmd)->endpoint = (*list)->lexema;
		(*prev) = (*list)->lexema;
		(*list) = (*list)->next;
	}
}

static int	is_redirect(int prev, int curr)
{
	if (curr >= LESS && curr <= DGREAT)
		return (1);
	if (prev >= LESS && prev <= DGREAT)
		return (1);
	return (0);
}
