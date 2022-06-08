#include "minishell.h"

static int	built_in_utils(t_cmd *cmd);
int			built_in_cmd(t_cmd *cmd);

//Essas built_ins não passam os retornos para o pipe, então são executadas no proceso parent.
int	check_built_in(t_cmd *cmd)
{
	if (ft_strncmp(cmd->exec[0], "cd\0", 3) == 0
		|| ft_strncmp(cmd->exec[0], "export\0", 7) == 0
		|| ft_strncmp(cmd->exec[0], "unset\0", 6) == 0
		|| ft_strncmp(cmd->exec[0], "exit\0", 5) == 0)
	{
		built_in_cmd(cmd);
		return (0);
	}
	
/*	else if (ft_strncmp((*s_cmd)->words[0][0], "ASSIGNMENT_WORD", 15) == 0)
	{
		built_in_cmd(tkn, tkn->i_cmd);
		return (0);
	}
*/	return (1);
}

int	built_in_cmd(t_cmd *cmd)
{
	int	ret;

	ret = 0;
	if (ft_strncmp(cmd->exec[0], "echo\0", 5) == 0)
	{
		echo(cmd->exec[1], &cmd->exec[1]);
		return (ret);
	}
	else if (ft_strncmp(cmd->exec[0], "PWD\0", 4) == 0)
	{
		pwd();
		return (ret);
	}
	if (ft_strncmp(cmd->exec[0], "cd\0", 3) == 0)
	{
		cd(cmd->exec[1]);
		return (ret);
	}
	else
	{
		ret = built_in_utils(cmd);
		return (ret);
	}
	return (1);
}

static int	built_in_utils(t_cmd *cmd)
{
	char	**temp;
	
	if (ft_strncmp(cmd->exec[0], "export\0", 7) == 0)
	{
		temp = ft_split(cmd->exec[1], '=');
		export(ft_strdup(temp[0]), ft_strdup(temp[1]));
		free(temp[0]);
		free(temp[1]);
		free(temp);
		return (0);
	}
	else if (ft_strncmp(cmd->exec[0], "unset\0", 6) == 0)
	{
		temp = ft_split(cmd->exec[1], '=');
		unset(temp[1]);
		free(temp[0]);
		free(temp[1]);
		free(temp);
		return (0);
	}
	else if (ft_strncmp(cmd->exec[0], "env\0", 4) == 0)
	{
		if (cmd->exec[1] == NULL)
			env();
		else
			error(cmd->exec[1], -6, 127);
		return (0);
	}
/*	else if (ft_strncmp(cmd->exec[0], "exit\0", 5) == 0)
	{
		exit(cmd);
		return (0);
	}
*/
	return (1);
}
