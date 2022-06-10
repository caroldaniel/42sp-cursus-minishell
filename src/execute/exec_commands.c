/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:34:51 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/10 12:47:38 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_child(t_cmd *cmd);
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
	int		pid;
	int		wstatus;
	int		i;

	cmd = g_data.cmd;
	i = 0;
	while (cmd != NULL)
	{
		if (*cmd->exec != NULL && cmd->fd_in != -1)
		{
			if (is_not_forked(cmd) == 1)
			{
				if (cmd_setup(cmd) == 0)
				{
					pid = fork();
					if (pid < 0)
						error(0, 0, 11); //verificar
					i++;
					if (pid == 0)
						exec_child(cmd);
				}
			}
		}
		close_fd(cmd, 1);
		cmd = cmd->next;
	}
	while (i > 0)
	{
		waitpid(pid, &wstatus, 0);
		i--;
	}
}

static int	exec_child(t_cmd *cmd)
{
//	handle_signal_child();
	close_fd(cmd, 0);
	if (built_in_cmd(cmd) == 1)
	{
		if (execve(cmd->exec_path, cmd->exec, NULL) == -1)
		{
			error(cmd->exec[0], -6, 13);
			clear();
			exit(1);
		}
		clear();
	}
	printf("exec_child.....");
	clear();
	exit(0);
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