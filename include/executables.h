/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:37 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/05 15:49:22 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTABLES_H
# define EXECUTABLES_H

# include "minishell.h"
# include "parser.h"
# include <errno.h>

# define MAX_PID	1024

enum e_fd {
	IN,
	OUT,
	BOTH
};

void	exec_line(void);

/*
** Workflow
*/

void	open_pipes(void);
int		define_redirects(void);
void	exec_commands(void);
void	exec_commands_parent_signals(void);
void	exec_commands_child_signals(void);

/*
** Built-ins
*/

int		ft_exit(char **exec);
int		ft_echo(char **exec);
int		ft_export(char **exec);
int		ft_set(char **exec);
int		ft_unset(char **exec);
int		ft_env(t_cmd *cmd);
int		ft_cd(char **exec);
int		ft_pwd(void);
void	assign_word(t_cmd *cmd);
char	*get_pwd(void);
int		is_builtin(t_cmd *cmd);
int		is_forked(t_cmd *cmd);
void	exec_builtin_in_child(t_cmd *cmd);
void	exec_builtin_in_parent(t_cmd *cmd);
void	exec_command(t_cmd *cmd);
void	exec_child(t_cmd *cmd);
void	wait_all_pids(int pid[MAX_PID], int id);

/*
** Here document
*/

int		get_heredoc(char *limiter);
void	get_heredoc_parent_signal(void);
void	get_heredoc_child_signal(void);
void	expand_limiter(char **lim, int *flag);
void	expand_line(char **line, int flag);

/*
** Utils
*/

char	*get_path(t_cmd *cmd);
void	close_fds(void);
void	close_fd(t_cmd *cmd, int flag);
void	change_exec(t_cmd *cmd, int pos);

#endif