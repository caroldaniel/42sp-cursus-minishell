#include "minishell.h"

static int	path_setup(t_cmd *cmd);
static char	**create_path(char ***path);
static void	free_path(char **path);
static void built_cmd_path(t_cmd *cmd, char *path);

int	cmd_setup(t_cmd *cmd)
{
	int	ret;

	ret = 0;
	if (ft_strchr(cmd->exec[0], '/') == NULL)
	{
		//if (built in)
		ret = path_setup(cmd);
	}
	else
		cmd->exec_path = ft_strdup(cmd->exec[0]);
	return (ret);
}

static int	path_setup(t_cmd *cmd)
{
	int		x;
	char	**path;

	create_path(&path);
	x = 0;
	if (path != NULL)
	{
		while (path[x] != NULL)
		{
			built_cmd_path(cmd, path[x]);
			if (cmd->exec_path == NULL)
				exit(1); //verificar erro
			if (access(cmd->exec_path, F_OK) == 0)
			{
				free_path(path);
				return (0);
			}
			free(cmd->exec_path);
			cmd->exec_path = NULL;
			x++;
		}
	}
	free(path);
	error(cmd->commands->token, -7, 127);
	return (1);
}

static void built_cmd_path(t_cmd *cmd, char *path)
{
	char	*temp;

	cmd->exec_path = ft_strjoin(path, "/");
	if (cmd->exec_path == NULL)
		exit(1); //verificar qual o comportamento
	temp = cmd->exec_path;
	cmd->exec_path = ft_strjoin(temp, cmd->commands->token);
	free(temp);

}
static char	**create_path(char	***path)
{
	char	*temp;

	temp = key_search(BOTH, "PATH");
	*path = ft_split(temp, ':');
	return (*path);
}

static void	free_path(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}
