/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:34:51 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 09:10:03 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_child(t_cmd *cmd);
static void	close_all_fds(void);
static void	close_fd(t_cmd *cmd, int flag);
static void	exit_errno(t_cmd *cmd);

/*	EXEC_COMMANDS
**	-------------
**	DESCRIPTION
**	It executes the t_cmd list of commands, one by one, by priority status. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	exec_commands(void)
{
	t_cmd	*cmd;
	int		pid[MAX_PID];
	int		wstatus;
	int		i;

	cmd = g_data.cmd;
	i = -1;
	while (cmd)
	{
		if (cmd->fd_in == -1 || cmd->fd_out == -1)
			exit_errno(cmd);
		else if (*cmd->exec && !is_forked(cmd) && !get_path(cmd))
		{
			pid[++i] = fork();
			if (pid[i] == -1)
				error(NULL, 0, 11);
			if (pid[i] == 0)
				exec_child(cmd);
		}
		cmd = cmd->next;
	}
	close_all_fds();
	while (i-- >= 0)
		waitpid(pid[i], &wstatus, 0);
}

static int	exec_child(t_cmd *cmd)
{
	close_fd(cmd, 0);
	close_all_fds();
	if (built_in_cmd(cmd) == 1)
	{
		if (execve(cmd->exec_path, cmd->exec, NULL) == -1)
		{
			error(cmd->exec[0], -8, 13);
			clear();
			exit(1);
		}
		clear();
	}
	clear();
	exit(0);
}

static void	close_all_fds(void)
{
	t_cmd	*cmd;
	
	cmd = g_data.cmd;
	while (cmd)
	{
		close_fd(cmd, 1);
		cmd = cmd->next;
	}	
}

static void	close_fd(t_cmd *cmd, int flag)
{
	if (cmd->fd_in > 2)
	{
		if (flag == 0)
			dup2(cmd->fd_in, STDIN_FILENO);
		close(cmd->fd_in);
	}
	if (cmd->fd_out > 2)
	{
		if (flag == 0)
			dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
}

static void	exit_errno(t_cmd *cmd)
{
	if (cmd->errnb == 2)
		error(cmd->errfile, -7, 1);
	if (cmd->errnb == 13)
		error(cmd->errfile, -6, 1);
}