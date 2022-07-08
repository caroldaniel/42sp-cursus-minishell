/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:13:34 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/05 13:22:11 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin_in_parent(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->exec_path, "cd\0", 3))
		g_data.exit_code = ft_cd(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "export\0", 7))
		g_data.exit_code = ft_export(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "unset\0", 6))
		g_data.exit_code = ft_unset(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "exit\0", 5))
		g_data.exit_code = ft_exit(cmd->exec);
	else if (is_assign_word(cmd->exec_path))
		assign_word(cmd);
	envp_swap(cmd);
}

void	exec_builtin_in_child(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->exec_path, "env\0", 4))
		g_data.exit_code = ft_env(cmd);
	else if (!ft_strncmp(cmd->exec_path, "export\0", 7))
		g_data.exit_code = ft_export(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "echo\0", 5))
		g_data.exit_code = ft_echo(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "pwd\0", 4))
		g_data.exit_code = ft_pwd();
}
