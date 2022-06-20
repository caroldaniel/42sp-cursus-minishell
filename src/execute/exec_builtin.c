/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:13:34 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/19 21:41:13 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->exec[0], "echo\0", 5))
		return (1);
	else if (!ft_strncmp(cmd->exec[0], "pwd\0", 4))
		return (1);
	else if (!ft_strncmp(cmd->exec[0], "cd\0", 3))
		return (1);
	else if (!ft_strncmp(cmd->exec[0], "export\0", 7))
		return (1);
	else if (!ft_strncmp(cmd->exec[0], "unset\0", 6))
		return (1);
	else if (!ft_strncmp(cmd->exec[0], "env\0", 4))
		return (1);
	else if (!ft_strncmp(cmd->exec[0], "exit\0", 5))
		return (1);
	else if (cmd->commands->lexema == ASSIGN_WORD)
		return (1);
	return (0);
}

void	exec_builtin(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->exec_path, "exit\0", 5))
		g_data.exit_code = ft_exit(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "export\0", 7))
		g_data.exit_code = ft_export(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "unset\0", 6))
		g_data.exit_code = ft_unset(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "env\0", 4))
		g_data.exit_code = ft_env(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "echo\0", 5))
		g_data.exit_code = ft_echo(cmd->exec);
	else if (ft_strncmp(cmd->exec_path, "pwd\0", 4) == 0)
		g_data.exit_code = ft_pwd();
	else if (ft_strncmp(cmd->exec_path, "cd\0", 3) == 0)
		g_data.exit_code = ft_cd(cmd->exec);
	envp_swap();
}

int	is_forked(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->exec_path, "cd\0", 3)
		|| !ft_strncmp(cmd->exec_path, "export\0", 7)
		|| !ft_strncmp(cmd->exec_path, "unset\0", 6)
		|| !ft_strncmp(cmd->exec_path, "exit\0", 5))
	{
		if (!cmd->is_piped)
			exec_builtin(cmd);
		return (0);
	}
	if (cmd->commands->lexema == ASSIGN_WORD)
	{
		if (!cmd->is_piped)
			ft_set(cmd->exec);
		return (0);
	}
	return (1);
}
