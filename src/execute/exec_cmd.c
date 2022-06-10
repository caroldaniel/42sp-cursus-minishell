#include "minishell.h"

static void	exec_cmd(t_cmd *cmd);
static int	exec_child(t_cmd *cmd);
static void	create_pipes(t_cmd *cmd);
static void	close_fd(t_cmd *cmd, int flag);

void	exec_cmd_tab(void)
{
	t_cmd	*cmd;
//	int		temp_in;
	
//	temp_in = dup(STDIN_FILENO);
	cmd = g_data.cmd;
	create_pipes(cmd);
	define_std_fileno(cmd);
	exec_cmd(cmd);
//	dup2(temp_in, STDIN_FILENO);
}

static void	create_pipes(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->endpoint == PIPE)
		{
			if (pipe(tmp->fd_pipe) == -1)
				error(NULL, 0, 11);
			tmp->fd_out = tmp->fd_pipe[1];
			tmp->next->fd_in = tmp->fd_pipe[0];
		}
		tmp = tmp->next;
	}
}

static void	exec_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		pid;
	int		wstatus;
	int		i;

	tmp = cmd;
	i = 0;
	while (tmp != NULL)
	{
		if (*tmp->exec != NULL && tmp->fd_in != -1)
		{
			if (is_not_forked(tmp) == 1)
			{
				if (cmd_setup(tmp) == 0)
				{
					pid = fork();
					if (pid < 0)
						error(0, 0, 11); //verificar
					i++;
					if (pid == 0)
						exec_child(tmp);
				}
			}
		}
		close_fd(cmd, 1);
		tmp = tmp->next;
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