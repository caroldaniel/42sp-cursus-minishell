/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:09:27 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 19:07:20 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_tilde_expandable(char *home, char *parameter);
static char	*expand_tilde(char	*home, char *parameter, int *pos);

/*	TILDE_EXPANSION
**	---------------
**	DESCRIPTION
**	It expands the tilde symbol into a full home directory path, using the HOME 
**	environment variable.
**	PARAMETERS
**	#1. The token to expand.
**	RETURN VALUES
**	The expanded string, if appliable. NULL if no tilde expansion was found.
**	OBSERVATIONS
**	This function is interpreted differently according to each shell interface
**	that we might work upon. However, as it came to our attention during the
**	research for this project is that the tilde expansion doesn't necessarily 
**	occur over the HOME environment variables. Tilde expands accordingly to the 
**	system user's name and id. To be able to correctly simulate this behaviour,
**	we should be able to use the functions getpwuid() and getuid() - both must
**	include sys/types.h and pwd.h header files - which are able to access the 
**	kernel's information about the current user process. However, they are not 
**	allowed by minishell's current subject. Therefore we were forced to simplify
**	the original function behaviour. 
*/

void	tilde_expansion(t_tkn **tkn, int *pos)
{
	char	*home;
	char	*parameter;

	home = key_search("HOME");
	if (!home)
		return ;
	parameter = NULL;
	if ((*tkn)->token[(*pos) + 1])
		parameter = ft_strdup(&(*tkn)->token[(*pos) + 1]);
	if (is_tilde_expandable(home, parameter))
		swap_token(*tkn, expand_tilde(home, parameter, pos));
	if (parameter)
		free(parameter);
}

static int	is_tilde_expandable(char *home, char *parameter)
{
	char	*logname;
	int		login_len;

	logname = &ft_strrchr(home, '/')[1];
	login_len = ft_strlen(logname);
	if (!parameter || *parameter == '/')
		return (1);
	if (!ft_strncmp(parameter, logname, login_len))
		if (parameter[login_len] == 0 || parameter[login_len] == '/')
			return (1);
	return (0);
}

static char	*expand_tilde(char	*home, char *parameter, int *pos)
{
	char	*logname;
	char	*result;

	logname = &ft_strrchr(home, '/')[1];
	if (!parameter)
		result = ft_strdup(home);
	else if (!ft_strncmp(parameter, logname, ft_strlen(logname)))
		result = ft_strjoin(home, &parameter[ft_strlen(logname)]);
	else
		result = ft_strjoin(home, parameter);
	*pos = ft_strlen(home);
	return (result);
}
