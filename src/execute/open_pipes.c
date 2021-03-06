/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:39:39 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 22:41:14 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	OPEN_PIPES
**	----------
**	DESCRIPTION
**	This function opens all necessary pipes by the previously defined
**	PIPE endpoints, and determines the correct file descriptors for 
**	input and output of the executables. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	open_pipes(void)
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
			cmd->is_piped = 1;
			cmd->next->fd_in = cmd->fd_pipe[0];
			cmd->next->is_piped = 1;
		}
		cmd = cmd->next;
	}
}
