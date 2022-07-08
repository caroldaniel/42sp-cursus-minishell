/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:44:58 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/21 08:45:13 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dir_delete(t_dir **list)
{
	t_dir	*dir;
	t_dir	*tmp;

	dir = *list;
	while (dir)
	{
		tmp = dir;
		dir = dir->next;
		free(tmp->file);
		free(tmp);
	}
}
