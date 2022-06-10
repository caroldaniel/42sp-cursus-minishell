/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:16:03 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/10 17:17:56 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_to_pipe(char *limiter, int *fd);

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
	int		fd[2];

	if (pipe(fd) == -1)
	{
		error(NULL, 0, 11);
		return (-1);
	}
	printf("fd[0] = %d\n", fd[0]);
	printf("fd[1] = %d\n", fd[1]);
	close(fd[0]);
	write_to_pipe(limiter, fd);
	return (fd[1]);
}

static void	write_to_pipe(char *limiter, int *fd)
{
	char	*line;
	int		lim_len;

	lim_len = ft_strlen(limiter);
	line = readline("> ");
	printf("linha: %s\n", line);
	while (line)
	{
		if (!ft_strncmp(limiter, line, lim_len) && line[lim_len] == '\0')
			break ;
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
		line = readline("> ");
		printf("linha: %s\n", line);
	}
	free(line);
}
