/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:41:13 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/04 11:00:39 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_env(t_cmd *cmd);
static void	add_to_envp(t_cmd *cmd, char *variable);
static int	env_exists(t_cmd *cmd, char *variable);

/*	FT_ENV
**	------
**	DESCRIPTION
**	Prints the envp complete list of environment variables.
**	PARAMETERS
**	#1. The complete exec list of parameters.
**	RETURN VALUES
**	-
*/

int	ft_env(t_cmd *cmd)
{
	size_t		i;
	char		**exec;
	int			ret;

	exec = cmd->exec;
	ret = 127;
	if (!key_search("PATH"))
		error(exec[0], -51, ret);
	else if (!exec[1] || !*exec[1])
	{
		i = -1;
		while (cmd->envp[++i])
			printf("%s\n", cmd->envp[i]);
		ret = 0;
	}
	else
		execute_env(cmd);
	return (ret);
}

static void	execute_env(t_cmd *cmd)
{
	int	pos;

	pos = 0;
	while (is_assign_word(cmd->exec[++pos]))
		add_to_envp(cmd, cmd->exec[pos]);
	change_exec(cmd, pos);
	exec_command(cmd);
	error(NULL, 0, g_data.exit_code);
}

static void	add_to_envp(t_cmd *cmd, char *variable)
{
	char	**new_envp;
	int		i;

	if (env_exists(cmd, variable))
		return ;
	new_envp = ft_calloc(sizeof(char *), envp_length(cmd->envp) + 2);
	if (!new_envp)
		error(NULL, 0, 11);
	i = -1;
	while (cmd->envp[++i])
		new_envp[i] = ft_strdup(cmd->envp[i]);
	new_envp[i] = ft_strdup(variable);
	envp_clear(cmd);
	cmd->envp = new_envp;
}

static int	env_exists(t_cmd *cmd, char *variable)
{
	int		i;
	char	*key;
	size_t	size;

	i = -1;
	key = get_key(variable);
	size = ft_strlen(key);
	while (cmd->envp[++i])
	{
		if (!ft_strncmp(cmd->envp[i], key, size) && cmd->envp[i][size] == '=')
		{
			free(cmd->envp[i]);
			cmd->envp[i] = ft_strdup(variable);
			free(key);
			return (1);
		}
	}
	free(key);
	return (0);
}
