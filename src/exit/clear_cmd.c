/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:16:17 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 09:21:39 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear_exec_list(char **exec);
//static void	clear_exec_path(char *exec_path);

/*	CLEAR_CMD
**	---------
**	DESCRIPTION
**	The clear_cmd function will free the entire t_cmd struct inside the 
**	main global structure, clearing the command and redirect token's list, the 
**	exec array and the exec_path string. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	clear_cmd(void)
{
	t_cmd	*curr;
	t_cmd	*tmp;

	curr = g_data.cmd;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		clear_tokens(&tmp->commands);
		clear_tokens(&tmp->redirects);
		clear_exec_list(tmp->exec);
		//clear_exec_path(tmp->exec_path);
		if (tmp->exec_path != NULL)
			free(tmp->exec_path);
		free(tmp);
	}
	g_data.cmd = NULL;
}

static void	clear_exec_list(char **exec)
{
	int	i;

	if (!exec)
		return ;
	i = -1;
	while (exec[++i])
		free(exec[i]);
	free(exec);
}
