/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 08:26:30 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/29 16:33:36 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_variable(char *parameter);
static void	cd_cmd(char *path);

/*	CD
**	--
**	DESCRIPTION
**	Changes the current working directory to a specified one.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	cd(char *parameter)
{
	if (parameter == NULL)
		cd_variable("HOME");
	else if (!ft_strncmp(parameter, "-", 2))
		cd_variable("OLDPWD");
	else
		cd_cmd(parameter);
}

static void	cd_variable(char *parameter)
{
	char	**oldpwd;
	char	*path;

	oldpwd = ft_split("OLDPWD", ' ');
	path = key_search(BOTH, parameter);
	if (!path)
	{
		error(parameter, -1, 1);
		return ;
	}
	if (!ft_strncmp("-", parameter, 2))
		echo(NULL, oldpwd);
	cd_cmd(parameter);
	g_data.exit_code = 0;
}

static void	cd_cmd(char *path)
{
	char	*key_oldpwd;
	char	*key_pwd;
	char	*value_oldpwd;

	value_oldpwd = get_pwd();
	if (chdir(path) == -1)
	{
		error(path, -2, 1);
		return ;
	}
	key_pwd = ft_strdup("PWD");
	key_oldpwd = ft_strdup("OLDPWD");
	set(key_oldpwd, value_oldpwd);
	set(key_pwd, path);
	g_data.exit_code = 0;
}
