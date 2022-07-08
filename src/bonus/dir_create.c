/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:37:06 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/22 09:04:15 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dir	*dir_create(char *file, int id)
{
	t_dir *dir;

	dir = malloc(sizeof(t_dir));
	if (!dir)
		return (NULL);
	dir->id = id;
	dir->file = file;
	dir->next = NULL;
	return (dir);
}
