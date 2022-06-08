#include "minishell.h"

static int	path_setup(t_cmd *cmd);
static char	**create_path(void);
static void	free_path(char **path);

int	cmd_setup(t_cmd *cmd)
{
	int	ret;

	ret = 0;
	if (ft_strchr(cmd->commands->token, '/') == NULL)
	{
		//if (built in)
		ret = path_setup(cmd);
	}
	return (ret);
}

static int	path_setup(t_cmd *cmd)
{
	int		x;
	char	*temp;
	char	**path;

	path = create_path();
	x = 0;
	if (path != NULL)
	{
		while (path[x] != NULL)
		{
			cmd->exec_path = ft_strjoin(path[x], "/");
			if (cmd->exec_path == NULL)
				exit(1);
			temp = cmd->exec_path;
			cmd->exec_path = ft_strjoin(temp, cmd->commands->token);
			free(temp);
			if (cmd->exec_path == NULL)
				exit(1);
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

static char	**create_path(void)
{
	char	*temp;
	char	**path;

	temp = key_search(BOTH, "PATH");
	path = ft_split(temp, ':');
	return (path);
}

static void	free_path(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}
