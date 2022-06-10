/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:43:10 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/10 11:34:36 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_fileno(t_cmd *cmd);

void		exec_here_doc(t_cmd *cmd);
static int	exec_cmd(char *limiter);
static void	wr_line(char *limiter, int len, int fd[]);

void	define_redirects(void)
{
	t_cmd	*cmd;

	cmd = g_data.cmd;
	while (cmd)
	{
		while (cmd->redirects)
			redirect_std_fileno(cmd);
		if (cmd->fd_in == -2)
			cmd->fd_in = STDIN_FILENO;
		if (cmd->fd_out == -2)
			cmd->fd_out = STDOUT_FILENO;
		cmd = cmd->next;
	}
}

static void	get_fileno(t_cmd *cmd)
{
	if (cmd->fd_out == -1 || cmd->fd_in == -1)
		return ;
	if(cmd->fd_out != -2)
		close(cmd->fd_out);
	if (cmd->redirects->lexema == DGREAT)
		cmd->fd_out = open(cmd->redirects->next->token, O_RDWR | O_APPEND
				| O_CREAT, 0777);
	else if (cmd->redirects->lexema == GREAT)
		cmd->fd_out = open(cmd->redirects->next->token, O_RDWR | O_TRUNC
				| O_CREAT, 0777);
	else if (cmd->redirects->lexema == LESS)
		cmd->fd_in = open(cmd->redirects->next->token, O_RDONLY);
		// if (cmd->fd_in == -1)
		// {
		// 	if (errno == EACCES)
		// 		error(cmd->redirects->token, -6, 1);
		// 	if (errno == ENOENT)
		// 		error(cmd->redirects->token, -7, 1);
		// }
	else if (cmd->redirects->lexema == DLESS)
		exec_here_doc(cmd);
	cmd->errnb = errno;
	cmd->redirects = cmd->redirects->next->next;
}

void	exec_here_doc(t_cmd *cmd)
{
	char	*limiter;
	int		fd;
	
	limiter = cmd->redirects->next->token;
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