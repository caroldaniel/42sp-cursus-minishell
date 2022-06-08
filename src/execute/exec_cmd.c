#include "minishell.h"

static int	check_built_in(t_cmd *cmd);
static void	exec_cmd(t_cmd *cmd);
static int	exec_child(t_cmd *cmd);
static void	create_pipes(t_cmd *cmd);

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
	t_cmd	*temp;

	temp = cmd;
	while (temp)
	{
		temp->fd_in = -2;
		temp->fd_out = -2;
		temp = temp->next;
	}
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

static void	exec_cmd(t_cmd *cmd)
{
	int	pid;
	int	wstatus;
	int	i;

	i = 0;
	while (cmd != NULL)
	{
		if (*cmd->exec != NULL && cmd->fd_in != -1)
		{
			if (check_built_in(cmd) == 1)
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
		if (cmd->fd_in > 2)
			close(cmd->fd_in);
		if (cmd->fd_out > 2)
			close(cmd->fd_out);
		cmd = cmd->next;
	}
	while (i > 0)
	{
		waitpid(pid, &wstatus, 0);
		i--;
	}
}

static int	check_built_in(t_cmd *cmd)
{
	if (ft_strncmp(cmd->commands->token, "cd\0", 3) == 0)
	{
//		built_in_cmd(cmd);
		return (0);
	}
	if (ft_strncmp(cmd->commands->token, "export\0", 7) == 0)
	{
//		built_in_cmd(cmd);
		return (0);
	}
	if (ft_strncmp(cmd->commands->token, "unset\0", 7) == 0)
	{
//		built_in_cmd(cmd);
		return (0);
	}
	if (ft_strncmp(cmd->commands->token, "exit\0", 5) == 0)
	{
//		built_in_cmd(cmd);
		return (0);
	}
/*	else if (ft_strncmp((*s_cmd)->words[0][0], "ASSIGNMENT_WORD", 15) == 0)
	{
		built_in_cmd(tkn, tkn->i_cmd);
		return (0);
	}
*/	return (1);
}

static int	exec_child(t_cmd *cmd)
{
//	handle_signal_child();
	printf("cmd_fd_in %d\n", cmd->fd_in);
	printf("cmd_fd_out %d\n", cmd->fd_out);
	if (cmd->fd_in != STDIN_FILENO)
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != STDOUT_FILENO)
	{
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
//	if (built_in_cmd(cmd) == 1)
	{
		if (execve(cmd->exec_path, cmd->exec, NULL) == -1)
		{
			write(2, "error execve\n", 13);
			exit(1);
		}
//		exit_shell(tkn, s_cmd);
	}
//	exit_shell(tkn, s_cmd);
//	free_tab(&tkn->envp, tkn->envp_count);
//	rl_clear_history();
//	exit(0);
	return (0);
}
