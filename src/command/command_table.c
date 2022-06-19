/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:12:29 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/19 14:07:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cmd_populate(t_cmd **cmd, t_tkn **list, int *prev, int *lvl);
static void	cmd_populate_full(t_cmd **cmd, t_tkn **list, int *prev, int *lvl);
static int	is_redirect(int prev, int cur);
static int	change_lvl(t_tkn *list);

/*	COMMAND_TABLE
**	-------------
**	DESCRIPTION
**	The command_table function will assemble the t_tkn list into two different 
**	commands and redirect list, using the operators as endpoints to simple
**	commands (ordered into a t_cmd list).
**	PARAMETERS
**	-
**	RETURN VALUES
**	- 
*/

void	command_table(void)
{
	t_cmd	*cmd_node;
	t_tkn	*list;
	int		prev;
	int		id;
	int		lvl;

	list = g_data.parser->tokens;
	prev = -1;
	id = 0;
	lvl = 0;
	while (list)
	{
		cmd_node = cmd_create(id);
		cmd_populate(&cmd_node, &list, &prev, &lvl);
		cmd_add_back(cmd_node);
		id++;
	}
	command_expansion();
	command_list();
}

static void	cmd_populate(t_cmd **cmd, t_tkn **list, int *prev, int *lvl)
{
	if ((*list)->lexema == PARENTHESIS)
	{
		*lvl = *lvl + change_lvl(*list);
		(*list) = (*list)->next;
	}
	(*cmd)->priority_level = *lvl;
	if ((*list)->lexema == ASSIGN_WORD)
	{
		tkn_add_back(&(*cmd)->commands, tkn_dup(*list));
		(*cmd)->priority_level = *lvl;
		(*prev) = (*list)->lexema;
		(*list) = (*list)->next;
		return ;
	}
	cmd_populate_full(cmd, list, prev, lvl);
}

static void	cmd_populate_full(t_cmd **cmd, t_tkn **list, int *prev, int *lvl)
{
	t_tkn	**destiny;

	while (*list && (*list)->lexema < PIPE)
	{
		destiny = &(*cmd)->commands;
		if (is_redirect(*prev, (*list)->lexema))
			destiny = &(*cmd)->redirects;
		if ((*list)->lexema == PARENTHESIS)
			*lvl = *lvl + change_lvl(*list);
		else
			tkn_add_back(destiny, tkn_dup(*list));
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

static int	change_lvl(t_tkn *list)
{
	if (list->token[0] == '(')
		return (1);
	if (list->token[0] == ')')
		return (-1);
	return (0);
}
