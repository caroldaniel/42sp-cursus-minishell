/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:21:50 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/05 13:21:11 by cado-car         ###   ########.fr       */
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
	else if (is_assign_word(cmd->exec[0]))
		return (1);
	return (0);
}

int	is_forked(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->exec_path, "cd\0", 3)
		|| !ft_strncmp(cmd->exec_path, "unset\0", 6)
		|| !ft_strncmp(cmd->exec_path, "exit\0", 5)
		|| is_assign_word(cmd->exec_path))
	{
		if (!cmd->is_piped)
			exec_builtin_in_parent(cmd);
		return (0);
	}
	else if (!ft_strncmp(cmd->exec_path, "export\0", 7)
		&& cmd->exec[1] && *cmd->exec[1])
	{
		if (!cmd->is_piped)
			exec_builtin_in_parent(cmd);
		return (0);
	}
	return (1);
}
