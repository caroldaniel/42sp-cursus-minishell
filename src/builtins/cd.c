/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 08:26:30 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/17 10:06:31 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cd_variable(char *variable);
static int	cd_cmd(char *path);
static char	**create_export_exec(char *pwd, char *oldpwd);
static void	free_export_exec(char **exec);

/*	FT_CD
**	-----
**	DESCRIPTION
**	Changes the current working directory to a specified one.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

int	ft_cd(char **exec)
{
	char	*parameter;
	int		ret;	

	parameter = exec[1];
	ret = 1;
	if (parameter && exec[2])
		error("cd", -4, 1);
	else if (!parameter)
		ret = cd_variable("HOME");
	else if (!ft_strncmp(parameter, "-", 2))
		ret = cd_variable("OLDPWD");
	else
		ret = cd_cmd(parameter);
	return (ret);
}

static int	cd_variable(char *variable)
{
	char	*path;
	int		ret;

	path = key_search(variable);
	ret = 1;
	if (!path)
		error(variable, -3, 1);
	else
	{
		if (!ft_strncmp("OLDPWD", variable, 6))
			printf("%s\n", path);
		ret = cd_cmd(path);
	}
	return (ret);
}

static int	cd_cmd(char *path)
{
	char	*oldpwd;
	char	*pwd;
	char	*curr_pwd;
	char	**exec;

	if (chdir(path) == -1)
	{
		error(path, -2, 1);
		return (1);
	}
	oldpwd = ft_strjoin("OLDPWD=", key_search("PWD"));
	curr_pwd = get_pwd();
	pwd = ft_strjoin("PWD=", curr_pwd);
	free(curr_pwd);
	exec = create_export_exec(pwd, oldpwd);
	ft_export(exec);
	free_export_exec(exec);
	return (0);
}

static char	**create_export_exec(char *pwd, char *oldpwd)
{
	char	**exec;
	char	*name;

	exec = ft_calloc(4, sizeof(char *));
	if (!exec)
		error(NULL, 0, 12);
	name = ft_strdup("export");
	exec[0] = name;
	exec[1] = pwd;
	exec[2] = oldpwd;
	return (exec);
}

static void	free_export_exec(char **exec)
{
	int	i;

	i = -1;
	while (exec[++i])
		free(exec[i]);
	free(exec);
}
