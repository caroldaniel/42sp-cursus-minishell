/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:39:39 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/11 19:29:18 by fausto           ###   ########.fr       */
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
			cmd->next->fd_in = cmd->fd_pipe[0];
		}
//		printf("PIPE\nfd_in = %d\tfd_out = %d\n", cmd->fd_in, cmd->fd_out);
		cmd = cmd->next;
	}
}
