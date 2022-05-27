/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:12:52 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 13:12:46 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmd_create(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		error(NULL, 0, 12);
	cmd->commands = NULL;
	cmd->redirects = NULL;
	cmd->exec = NULL;
	cmd->next = NULL;
	cmd->endpoint = -1;
	return (cmd);
}
