/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:43:10 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/10 16:59:52 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_fileno(int operator, char *filename, t_cmd *cmd);

/*	DEFINE_REDIRECTS
**	----------------
**	DESCRIPTION
**	This function will define STDIN and STDOUT of each command/process in line.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	define_redirects(void)
{
	t_cmd	*cmd;
	t_tkn	*redirects;

	cmd = g_data.cmd;
	while (cmd)
	{
		redirects = cmd->redirects;
		while (redirects)
		{
			if (cmd->fd_out == -1 || cmd->fd_in == -1)
				break ;
			get_fileno(redirects->lexema, redirects->next->token, cmd);
			redirects = redirects->next;
			redirects = redirects->next;
		}
		if (cmd->fd_in == -2)
			cmd->fd_in = STDIN_FILENO;
		if (cmd->fd_out == -2)
			cmd->fd_out = STDOUT_FILENO;
		cmd = cmd->next;
	}
}

static void	get_fileno(int operator, char *filename, t_cmd *cmd)
{
	if (operator == DGREAT || operator == GREAT)
	{
		if (cmd->fd_out != -2)
			close(cmd->fd_out);
	}
	else if (operator == DLESS || operator == LESS)
	{
		if (cmd->fd_in != -2)
			close(cmd->fd_out);
	}
	if (operator == DGREAT)
		cmd->fd_out = open(filename, O_RDWR | O_APPEND | O_CREAT, 0777);
	else if (operator == GREAT)
		cmd->fd_out = open(filename, O_RDWR | O_TRUNC | O_CREAT, 0777);
	else if (operator == LESS)
		cmd->fd_in = open(filename, O_RDONLY);
	else if (operator == DLESS){
		cmd->fd_in = get_heredoc(filename);
		printf("cmd->fd_in = %d\n", cmd->fd_in);}
	cmd->errnb = errno;
}
