/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:01:05 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/06 15:03:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**put_in_list(t_tkn *tkn);

void	command_list(void)
{
	t_cmd	*cmd;

	cmd = g_data.cmd;
	while (cmd)
	{
		cmd->exec = put_in_list(cmd->commands);
		cmd = cmd->next;
	}
}

static char	**put_in_list(t_tkn *tkn)
{
	int		size;
	char	**list;
	int		i;

	size = tkn_len(tkn) + 1;
	list = ft_calloc(sizeof(char *), size);
	i = 0;
	while (tkn)
	{
		list[i] = ft_strdup(tkn->token);
		tkn = tkn->next;
		i++;
	}
	return (list);
}
