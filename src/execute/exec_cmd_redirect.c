#include "minishell.h"

static void	redirect_std_fileno(void);
void	exec_here_doc(t_cmd *cmd);
static int	exec_cmd(char *limiter);
static void	wr_line(char *limiter, int len, int fd[]);

void	define_std_fileno(t_cmd *cmd)
{
	while (cmd)
	{
		redirect_std_fileno();
		if (cmd->fd_in == -2)
			cmd->fd_in = STDIN_FILENO;
		if (cmd->fd_out == -2)
			cmd->fd_out = STDOUT_FILENO;
		cmd = cmd->next;
	}
}

static void	redirect_std_fileno(void)
{
	t_cmd	*tmp;

	tmp = g_data.cmd;
	while (tmp->redirects != NULL)
	{
		if (tmp->redirects->lexema == DGREAT)
		{
			if(tmp->fd_out != -2)
				close(tmp->fd_out);
			tmp->redirects = tmp->redirects->next;
			tmp->fd_out = open(tmp->redirects->token, O_RDWR | O_APPEND
					| O_CREAT, 0777);
		}
		else if (tmp->redirects->lexema == GREAT)
		{
			if (tmp->fd_out != -2)
				close(tmp->fd_out);
			tmp->redirects = tmp->redirects->next;
			tmp->fd_out = open(tmp->redirects->token, O_RDWR | O_TRUNC
					| O_CREAT, 0777);
		}
		else if (tmp->redirects->lexema == LESS)
		{
			tmp->redirects = tmp->redirects->next;
			if (tmp->fd_in != -1)
			{
				if(tmp->fd_in != -2)
					close(tmp->fd_in);
				tmp->fd_in = open(tmp->redirects->token, O_RDONLY);
				if (tmp->fd_in == -1)
					error(tmp->redirects->token, -6, 1);
			}
		}
		else if (tmp->redirects->lexema == DLESS)
		{
			if(tmp->fd_in != -2)
				close(tmp->fd_in);
			tmp->redirects = tmp->redirects->next;
			exec_here_doc(tmp);
		}
		else
			break;
		tmp->redirects = tmp->redirects->next;
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
			error(limiter, -8, 0);
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