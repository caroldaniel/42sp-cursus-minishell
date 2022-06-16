/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:13:34 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 20:44:51 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_cmd *cmd)
{
	int		ret;

	if (!ft_strncmp(cmd->exec[0], "exit\0", 5))
		ft_exit();
	ret = 1;
	if (!ft_strncmp(cmd->exec[0], "export\0", 7))
		ret = ft_export(cmd->exec);
	else if (!ft_strncmp(cmd->exec[0], "unset\0", 6))
		ret = ft_unset(cmd->exec);
	else if (!ft_strncmp(cmd->exec[0], "env\0", 4))
		ret = ft_env(cmd->exec);
	else if (!ft_strncmp(cmd->exec[0], "echo\0", 5))
		ret = ft_echo(cmd->exec);
	else if (ft_strncmp(cmd->exec[0], "pwd\0", 4) == 0)
		ret = ft_pwd();
	else if (ft_strncmp(cmd->exec[0], "cd\0", 3) == 0)
		ret = ft_cd(cmd->exec);
	envp_swap();
	return (ret);
}

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
	return (0);
}

int	is_forked(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->exec[0], "cd\0", 3)
		|| !ft_strncmp(cmd->exec[0], "export\0", 7)
		|| !ft_strncmp(cmd->exec[0], "unset\0", 6)
		|| !ft_strncmp(cmd->exec[0], "exit\0", 5)
		|| !ft_strncmp(cmd->exec[0], "env\0", 4))
	{
		if (!cmd->is_piped)
			exec_builtin(cmd);
		return (1);
	}
	return (0);
}
