/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_populate_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:40:45 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/22 09:04:30 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dir	*dir_populate_list(char *directory)
{
	DIR				*dir;
	struct dirent	*dent;
	t_dir			*list;
	char			*filename;
	int				id;
	
    dir = opendir(directory);
	if (!dir)
		return (NULL);
	id = 0;
	dent = readdir(dir);
	filename = ft_strdup(dent->d_name);
	list = NULL;
	dir_add_sorted(&list, dir_create(filename, id));
	while (1)
	{
		dent = readdir(dir);
		if (!dent)
			break ;
		filename = ft_strdup(dent->d_name);
		if (ft_strncmp(filename, ".", 1))
			dir_add_sorted(&list, dir_create(filename, ++id));
	}
    closedir(dir);
	return (list);
}
