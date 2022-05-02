/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:28:22 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/02 14:36:37 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_line	*init_line(void)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		error(NULL, 1, 1);
	return (line);
}
