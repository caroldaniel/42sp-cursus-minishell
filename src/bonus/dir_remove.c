/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:43:45 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/21 08:44:02 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dir_remove(t_dir **list, int id)
{
	t_dir	*prev;
	t_dir	*curr;

	prev = NULL;
	curr = *list;
	while (curr)
	{
		if (curr->id == id)
		{
			if (!prev)
				*list = curr->next;
			else
				prev->next = curr->next;
			free(curr->file);
			free(curr);
			return ;
		}
		curr = curr->next;
	}
}
