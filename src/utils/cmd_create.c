/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:12:52 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/04 14:45:21 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	CMD_CREATE
**	----------
**	DESCRIPTION
**	It will malloc(3) and create a new t_cmd node, which is is a structure that
**	will be further populated by a simple command data (here pointing to NULL).
**	PARAMETERS
**	-
**	RETURN VALUES
**	A t_cmd node.
*/

t_cmd	*cmd_create(int id)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		error(NULL, 0, 12);
	cmd->id = id;
	cmd->commands = NULL;
	cmd->redirects = NULL;
	cmd->endpoint = -1;
	cmd->is_piped = 0;
	cmd->exec = NULL;
	cmd->exec_path = NULL;
	cmd->envp = NULL;
	cmd->fd_in = -2;
	cmd->fd_out = -2;
	cmd->errnb = 0;
	cmd->errfile = NULL;
	cmd->next = NULL;
	return (cmd);
}
