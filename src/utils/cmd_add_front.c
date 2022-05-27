/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:41:27 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 15:53:30 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_add_front(t_cmd *node)
{
	t_cmd	*cmd_list;
	t_cmd	*tmp;

	cmd_list = g_data.cmd;
	if (!cmd_list)
		g_data.cmd = node;
	else
	{
		tmp = cmd_list;
		g_data.cmd = node;
		g_data.cmd->next = tmp;
	}
}
