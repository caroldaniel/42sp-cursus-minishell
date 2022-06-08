#include "minishell.h"

static void	redirect_std_fileno(t_cmd *cmd);
void	exec_here_doc(t_cmd *cmd);
static int	exec_cmd(char *limiter);
static void	wr_line(char *limiter, int len, int fd[]);

void	define_std_fileno(t_cmd *cmd)
{
	while (cmd)
	{
		redirect_std_fileno(cmd);
		if (cmd->fd_in == -2)
			cmd->fd_in = STDIN_FILENO;
		if (cmd->fd_out == -2)
			cmd->fd_out = STDOUT_FILENO;
		cmd = cmd->next;
	}
}

static void	redirect_std_fileno(t_cmd *cmd)
{
	while (cmd->redirects != NULL)
	{
		if (cmd->redirects->lexema == DGREAT)
		{
			if(cmd->fd_out != -2)
				close(cmd->fd_out);
			cmd->redirects = cmd->redirects->next;
			cmd->fd_out = open(cmd->redirects->token, O_RDWR | O_APPEND
					| O_CREAT, 0777);
		}
		else if (cmd->redirects->lexema == GREAT)
		{
			if (cmd->fd_out != -2)
				close(cmd->fd_out);
			cmd->redirects = cmd->redirects->next;
			cmd->fd_out = open(cmd->redirects->token, O_RDWR | O_TRUNC
					| O_CREAT, 0777);
		}
		else if (cmd->redirects->lexema == LESS)
		{
			cmd->redirects = cmd->redirects->next;
			if (cmd->fd_in != -1)
			{
				if(cmd->fd_in != -2)
					close(cmd->fd_in);
				cmd->fd_in = open(cmd->redirects->token, O_RDONLY);
				if (cmd->fd_in == -1)
					error(cmd->redirects->token, -6, 1);
			}
		}
		else if (cmd->redirects->lexema == DLESS)
		{
			if(cmd->fd_in != -2)
				close(cmd->fd_in);
			cmd->redirects = cmd->redirects->next;
			exec_here_doc(cmd);
		}
		else
			break;
		cmd->redirects = cmd->redirects->next;
	}
}

void	exec_here_doc(t_cmd *cmd)
{
	char	*limiter;
	int		fd;
	
	limiter = cmd->redirects->token;
	fd = exec_cmd(limiter);
	cmd->fd_in = fd;
}

static int	exec_cmd(char *limiter)
{
	int	fd[2];
	int	len;
	
	if (pipe(fd) == -1)
		exit(write(1, "pipe error\n", 11));
	len = ft_strlen(limiter);
	wr_line(limiter, len, fd);
	close(fd[1]);
	return (fd[0]);
}

static void	wr_line(char *limiter, int len, int fd[])
{
	char	*line;

	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
		{
			write(2, "aviso de erro here_doc", 22);
			break ;
		}
		if (ft_strncmp(limiter, line, len) == 0)
		{
			if (line[len] == '\n')
			{
				free(line);
				get_next_line(-1);
				break ;
			}
			write(fd[1], line, ft_strlen(line));
		}
		else
		{
			write(fd[1], line, ft_strlen(line));
		}
		free(line);
	}
}