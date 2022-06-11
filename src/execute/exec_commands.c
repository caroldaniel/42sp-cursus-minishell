/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:34:51 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/11 10:27:32 by cado-car         ###   ########.fr       */
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
	int		pid;
	int		wstatus;
	int		i;

	cmd = g_data.cmd;
	i = 0;
	signal(SIGINT, interrupt_process);
	signal(SIGQUIT, quit_process);
	while (!cmd)
	{
		if (!*cmd->exec && cmd->fd_in != -1 && is_not_forked(cmd) && !cmd_setup(cmd))
		{
			pid = fork();
			if (pid == -1)
				error(NULL, 0, 11);
			i++;
			if (pid == 0)
				exec_child(cmd);
		}
		close_fd(cmd, 1);
		cmd = cmd->next;
	}
	while (--i + 1 > 0)
		waitpid(pid, &wstatus, 0);
}

static int	exec_child(t_cmd *cmd)
{
//	handle_signal_child();
	close_fd(cmd, 0);
	printf("EXEC\nfd_in = %d\tfd_out = %d\n", cmd->fd_in, cmd->fd_out);
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
