/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errno.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:16:59 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/07 10:34:42 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_errno(char *errfile, int errnb)
{
	if (errnb == EACCES)
		error(errfile, -50, 1);
	else if (errnb == ENOENT)
		error(errfile, -51, 1);
	else
		error(errfile, -5, 127);
}
