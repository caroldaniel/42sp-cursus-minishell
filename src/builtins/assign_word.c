/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:21 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/04 11:17:24 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	assign_word(t_cmd *cmd)
{
	t_tkn	*tmp;
	int		pos;
	int		i;

	tmp = cmd->commands;
	i = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->lexema == WORD)
		{
			pos = i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	if (!pos)
		ft_set(cmd->exec);
	else
	{
		change_exec(cmd, pos);
		exec_command(cmd);
	}
}

void	change_exec(t_cmd *cmd, int pos)
{
	t_tkn	*tkn;
	size_t	size;
	char	**list;
	int		i;

	tkn = cmd->commands;
	i = -1;
	while (++i < pos)
		tkn = tkn->next;
	size = tkn_len(tkn) + 1;
	list = ft_calloc(sizeof(char *), size);
	if (!list)
		error(NULL, 0, 11);
	i = -1;
	while (tkn)
	{
		list[++i] = ft_strdup(tkn->token);
		tkn = tkn->next;
	}
	clear_exec_list(cmd->exec);
	cmd->exec = list;
}
