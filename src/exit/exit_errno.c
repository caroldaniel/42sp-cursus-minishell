/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errno.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:16:59 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/18 21:08:53 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_errno(char *errfile, int errnb)
{
	if (errnb == EACCES)
		error(errfile, -50, 126);
	else if (errnb == ENOENT)
		error(errfile, -51, 127);
	else
		error(errfile, -5, 127);
}
