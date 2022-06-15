/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:34:51 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/15 10:53:34 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_child(t_cmd *cmd);
static void	close_all_fds(void);
static void	close_fd(t_cmd *cmd, int flag);

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
	int		pid[1024];
	int		wstatus;
	int		i;

	cmd = g_data.cmd;
	i = -1;
	while (cmd)
	{
		if (*cmd->exec && cmd->fd_in != -1 && !is_forked(cmd) && !get_path(cmd))
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
		else
			printf("Executed!\n");
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
		if (flag ==0)
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

