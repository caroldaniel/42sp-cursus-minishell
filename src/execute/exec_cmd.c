#include "minishell.h"

static void	create_pipes(void);
static void	exec_cmd(void);
static int	exec_child(t_cmd *cmd);
static void	close_fd(t_cmd *cmd, int flag);

void	exec_cmd_tab(void)
{
//	int		temp_in;
	
//	temp_in = dup(STDIN_FILENO);
	create_pipes();
	define_std_fileno();
	exec_cmd();
//	dup2(temp_in, STDIN_FILENO);
}

static void	create_pipes(void)
{
	t_cmd	*cmd;

	cmd = g_data.cmd;
	while (cmd)
	{
		if (cmd->endpoint == PIPE)
		{
			if (pipe(cmd->fd_pipe) == -1)
				error(NULL, 0, 11);
			cmd->fd_out = cmd->fd_pipe[1];
			cmd->next->fd_in = cmd->fd_pipe[0];
		}
		cmd = cmd->next;
	}
}

static void	exec_cmd(void)
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