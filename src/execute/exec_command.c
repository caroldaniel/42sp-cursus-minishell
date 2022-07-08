/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:15:46 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/04 11:03:51 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_command(t_cmd *cmd)
{
	pid_t	pid[MAX_PID];
	int		id;

	id = -1;
	ft_memset(pid, 0, MAX_PID);
	cmd->exec_path = get_path(cmd);
	if (cmd->fd_in == -1 || cmd->fd_out == -1)
		exit_errno(cmd->errfile, cmd->errnb);
	else if (cmd->exec_path)
	{
		pid[++id] = fork();
		if (pid[id] == -1)
			error(NULL, 0, 11);
		if (pid[id] == 0)
		{
			exec_child(cmd);
		}
	}
	close_fd(cmd, BOTH);
	wait_all_pids(pid, id);
}
