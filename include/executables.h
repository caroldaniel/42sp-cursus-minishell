/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:37 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/15 08:51:47 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTABLES_H
# define EXECUTABLES_H

# include "minishell.h"
# include "parser.h"
# include <errno.h>

# define MAX_PID	1024

void	exec_line(void);

/*
** Workflow
*/

void	open_pipes(void);
void	define_redirects(void);
void	exec_commands(void);
void	exec_commands_signals(void);

int		get_heredoc(char *limiter);
void	get_heredoc_child_signal(void);
void	get_heredoc_parent_signal(void);

int		get_path(t_cmd *cmd);
int		is_built_in(t_cmd *cmd);
int		is_forked(t_cmd *cmd);
int		built_in_cmd(t_cmd *cmd);

#endif