/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:16:17 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/06 15:07:44 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear_exec_list(char **exec);

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
