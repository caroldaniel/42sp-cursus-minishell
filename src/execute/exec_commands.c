/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:34:51 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/13 12:34:08 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_child(t_cmd *cmd);
static void	close_fd(t_cmd *cmd, int flag);
static void	quit_process(int signal);
static void	interrupt_process(int signal);

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
	i = 0;
	signal(SIGINT, interrupt_process);
	signal(SIGQUIT, quit_process);
	while (cmd != NULL)
	{
		if (*cmd->exec != NULL && cmd->fd_in != -1 && is_not_forked(cmd) ==1 && cmd_setup(cmd) == 0)
		{
			pid[i] = fork();
			if (pid[i] == -1)
				error(NULL, 0, 11);
			if (pid[i] == 0)
				exec_child(cmd);
			i++;
		}
		close_fd(cmd, 1);
		cmd = cmd->next;
	}
	while (--i >= 0)
		waitpid(pid[i], &wstatus, 0);
}

static int	exec_child(t_cmd *cmd)
{
//	handle_signal_child();
	printf("EXEC\nfd_in = %d\tfd_out = %d\n", cmd->fd_in, cmd->fd_out);
	close_fd(cmd, 0);
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

static void	quit_process(int signal)
{
	(void)signal;
	error(NULL, -9, 131);
}

static void	interrupt_process(int signal)
{
	(void)signal;
	error(NULL, -11, 130);
}
