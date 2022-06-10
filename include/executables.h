/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:37 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/10 08:11:27 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTABLES_H
# define EXECUTABLES_H

# include "minishell.h"
# include "parser.h"

void	exec_cmd_tab(void);
int		cmd_setup(t_cmd *cmd);
void	define_std_fileno(t_cmd *cmd);
int		is_built_in(t_cmd *cmd);
int		is_not_forked(t_cmd *cmd);
int		built_in_cmd(t_cmd *cmd);

#endif