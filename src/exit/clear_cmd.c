/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:16:17 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 15:52:44 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (tmp->exec)
			free(tmp->commands);
		free(tmp);
	}
	g_data.cmd = NULL;
}
