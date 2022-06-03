/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:09:27 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/03 09:25:26 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_tilde_expandable(char *login, char *param);
static char	*expand_tilde(char *home, char *login, char *param);

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

char	*tilde_expansion(char *token)
{
	char	*home;
	char	*login;
	char	*param;
	char	*result;

	if (token[0] != '~')
		return (NULL);
	home = key_search(BOTH, "HOME");
	if (!home)
		return (NULL);
	login = ft_strdup(&ft_strrchr(home, '/')[1]);
	param = NULL;
	if (token[1])
		param = ft_strdup(&token[1]);
	printf("param = %s\n", param);
	result = NULL;
	if (is_tilde_expandable(login, param))
		result = expand_tilde(home, login, param);
	if (param)
		free(param);
	if (login)
		free(login);
	return (result);
}

static int	is_tilde_expandable(char *login, char *param)
{
	size_t	login_size;
	size_t	param_size;

	login_size = ft_strlen(login);
	param_size = ft_strlen(param);
	if (!param || *param == '/')
		return (1);
	if (param_size >= login_size)
		if (param[login_size] == 0 || param[login_size] == '/')
			return (1);
	return (0);
}

static char	*expand_tilde(char *home, char *login, char *param)
{
	char	*result;

	if (!param)
		result = ft_strdup(home);
	else if (!ft_strncmp(param, login, ft_strlen(login)))
		result = ft_strnjoin(2, home, &param[ft_strlen(login)]);
	else
		result = ft_strnjoin(2, home, param);
	return (result);
}
