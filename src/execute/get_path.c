/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:11:00 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/17 00:15:59 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	path_setup(t_cmd *cmd);
static char	*get_full_path(t_cmd *cmd, char *path);
static char	**create_path_list(void);
static void	free_path_list(char **path);

int	get_path(t_cmd *cmd)
{
	int	ret;

	ret = 0;
	if (!is_builtin(cmd))
	{
		if (!ft_strchr(cmd->exec[0], '/'))
			ret = path_setup(cmd);
		else
			cmd->exec_path = ft_strdup(cmd->exec[0]);
	}
	return (ret);
}

static int	path_setup(t_cmd *cmd)
{
	char	**path_list;
	char	*curr_path;
	int		i;

	path_list = create_path_list();
	if (path_list)
	{
		i = -1;
		while (path_list[++i])
		{
			curr_path = get_full_path(cmd, path_list[i]);
			if (access(curr_path, F_OK) == 0)
			{
				cmd->exec_path = curr_path;
				free_path_list(path_list);
				return (0);
			}
			free(curr_path);
		}
		free_path_list(path_list);
	}
	error(cmd->commands->token, -51, 127);
	return (1);
}

static char	*get_full_path(t_cmd *cmd, char *path)
{
	char	*curr_path;

	curr_path = ft_strnjoin(3, path, "/", cmd->exec[0]);
	return (curr_path);
}

static char	**create_path_list(void)
{
	char	**path;
	char	*temp;

	path = NULL;
	temp = key_search("PATH");
	if (temp)
		path = ft_split(temp, ':');
	return (path);
}

static void	free_path_list(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}
