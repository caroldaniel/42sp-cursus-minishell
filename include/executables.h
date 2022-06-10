/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:37 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/10 11:10:13 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTABLES_H
# define EXECUTABLES_H

# include "minishell.h"
# include <errno.h>

void	exec_line(void);

/*
** Workflow
*/

void	open_pipes(void);
void	define_redirects(void);
void	exec_cmd(void);

int		cmd_setup(t_cmd *cmd);
int		is_built_in(t_cmd *cmd);
int		is_not_forked(t_cmd *cmd);
int		built_in_cmd(t_cmd *cmd);

#endif