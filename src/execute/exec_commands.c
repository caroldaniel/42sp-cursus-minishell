/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:34:51 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/23 17:34:24 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_pipe_block(t_cmd **cmd);
static void	exec_child(t_cmd *cmd);
static void dup2_close_fds(t_cmd *cmd);
static void	wait_all_pids(int pid[MAX_PID], int id);

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

	cmd = g_data.cmd;
	while (cmd)
	{
		exec_pipe_block(&cmd);
		while (cmd)
		{
			if (cmd->endpoint == AND_IF && g_data.exit_code == 0)
			{
				cmd = cmd->next;
				break ;
			}
			if (cmd->endpoint == OR_IF && g_data.exit_code != 0)
			{
				cmd = cmd->next;
				break ;
			}
			
			cmd = cmd->next;
		}
	}
}

static void	exec_pipe_block(t_cmd **cmd)
{
	pid_t	pid[MAX_PID];
	int		id;
	
	id = -1;
	ft_memset(pid, 0, MAX_PID);
	while (*cmd)
	{
		(*cmd)->exec_path = get_path(*cmd);
		if ((*cmd)->fd_in == -1 || (*cmd)->fd_out == -1)
			exit_errno((*cmd)->errfile, (*cmd)->errnb);
		else if ((*cmd)->exec_path && is_forked(*cmd) && (*cmd)->exec_path)
		{
			pid[++id] = fork();
			if (pid[id] == -1)
				error(NULL, 0, 11);
			if (pid[id] == 0)
				exec_child(*cmd);
		}
		close_fd(*cmd, BOTH);
		if ((*cmd)->endpoint == AND_IF || (*cmd)->endpoint == OR_IF)
			break ;
		*cmd = (*cmd)->next;
	}
	wait_all_pids(pid, id);
}

static void	exec_child(t_cmd *cmd)
{
	dup2_close_fds(cmd);
	if (is_builtin(cmd))
		exec_builtin(cmd);
	else
	{
		exec_commands_signals();
		printf("path: %s\n", cmd->exec_path);
		execve(cmd->exec_path, cmd->exec, g_data.environ->envp);
		exit_errno(cmd->exec[0], errno);
	}
	error(NULL, 0, g_data.exit_code);
}

static void	dup2_close_fds(t_cmd *cmd)
{
	if (cmd->fd_in > 2)
		dup2(cmd->fd_in, STDIN_FILENO);
	if (cmd->fd_out > 2)
		dup2(cmd->fd_out, STDOUT_FILENO);
	close_fds();
}

static void	wait_all_pids(int pid[MAX_PID], int id)
{
	int		max_id;
	int		wstatus;

	max_id = id;
	id = -1;
	wstatus = 0;
	while (++id <= max_id)
		waitpid(pid[id], &wstatus, 0);
	if (WIFEXITED(wstatus))
		g_data.exit_code = WEXITSTATUS(wstatus);
}
