/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:41:27 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 10:32:41 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	CMD_ADD_BACK
**	------------
**	DESCRIPTION
**	It will add a t_cmd node to the back of a t_cmd list.
**	PARAMETERS
**	#1. The t_cmd node to be added in the back of the t_cmd list in the global 
**	struct.
**	RETURN VALUES
**	-
*/

void	cmd_add_back(t_cmd *node)
{
	t_cmd	*cmd_list;

	cmd_list = g_data.cmd;
	if (!cmd_list)
		g_data.cmd = node;
	else
	{
		while (cmd_list->next)
			cmd_list = cmd_list->next;
		cmd_list->next = node;
	}
}
