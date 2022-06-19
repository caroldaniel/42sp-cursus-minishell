/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:22:50 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/18 20:05:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fds(void)
{
	t_cmd	*cmd;

	cmd = g_data.cmd;
	while (cmd)
	{
		close_fd(cmd, BOTH);
		cmd = cmd->next;
	}
}

void	close_fd(t_cmd *cmd, int flag)
{
	if ((flag == IN || flag == BOTH) && cmd->fd_in > 2)
		close(cmd->fd_in);
	if ((flag == OUT || flag == BOTH) && cmd->fd_out > 2)
		close(cmd->fd_out);
}
