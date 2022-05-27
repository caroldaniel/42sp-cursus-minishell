/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:41:27 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/27 09:52:35 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_add_back(t_cmd *node)
{
	t_cmd	*cmd_list;

	cmd_list = g_data.cmd;
	if (!cmd_list)
		g_data.cmd = node;
	else
	{
		while (cmd_list->next)
			cmd_list = cmd_list->next;
		cmd_list->next = node;
	}
}
