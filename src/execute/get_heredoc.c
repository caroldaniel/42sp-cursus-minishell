/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:16:03 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/20 10:01:05 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_to_pipe(char *limiter, int *fd);
static int	exit_heredoc(void);
static int	interrupt_heredoc(int *fd);

/*	GET_HEREDOC
**	-----------
**	DESCRIPTION
**	This function will execute a heredoc command, which consists of prompting
**	the user for a fd_in directed to the STDIN. This function will then proceed
**	to write such input to another file descriptor which will then be opened by
**	the command execution.
**	PARAMETERS
**	#1. A t_cmd struct variable.
**	RETURN VALUES
**	-
*/

int	get_heredoc(char *limiter)
{
	int	fd[2];
	int	pid;
	int	wstatus;

	if (pipe(fd) == -1)
		return (exit_heredoc());
	pid = fork();
	if (pid == -1)
		return (exit_heredoc());
	if (!pid)
	{
		close(fd[0]);
		write_to_pipe(limiter, &fd[1]);
	}
	get_heredoc_parent_signal();
	close(fd[1]);
	waitpid(pid, &wstatus, 0);
	if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) == 130)
		return (interrupt_heredoc(fd));
	return (fd[0]);
}

static void	write_to_pipe(char *limiter, int *fd)
{
	char	*line;
	int		len;

	get_heredoc_child_signal();
	line = readline("> ");
	len = ft_strlen(limiter);
	while (1)
	{
		if (!line)
			error(limiter, -52, 22);
		if (!line || (!ft_strncmp(limiter, line, len) && line[len] == '\0'))
			break ;
		write(*fd, line, ft_strlen(line));
		write(*fd, "\n", 1);
		free(line);
		line = readline("> ");
	}
	free(line);
	close(*fd);
	error(NULL, 0, 0);
}

static int	interrupt_heredoc(int *fd)
{
	close(fd[0]);
	return (-3);
}

static int	exit_heredoc(void)
{
	error(NULL, 0, -54);
	return (-3);
}
