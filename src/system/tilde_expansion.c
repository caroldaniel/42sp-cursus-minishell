/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:09:27 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/02 09:01:11 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	TILDE_EXPANSION
**	---------------
**	DESCRIPTION
**	It expands the tilde symbol into a full home directory path, using HOME and 
**	LOGNAME environment variables.
**	PARAMETERS
**	-
**	RETURN VALUES
**	The absolute path of home directory
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

char	*tilde_expansion(char *parameter)
{
	char	*extension;
	char	*home;
	char	*logname;
	size_t	size;

	home = key_search(BOTH, "HOME");
	logname = ft_strdup(&ft_strrchr(home, '/')[1]);
	size = ft_strlen(logname);
	extension = NULL;
	if (home)
	{
		if (!parameter)
			extension = ft_strdup(home);
		else if (parameter[0] == '/')
			extension = ft_strnjoin(2, home, parameter);
		else if (parameter && logname)
		{
			if (!ft_strncmp(parameter, logname, size))
			{
				if (!parameter[size] || parameter[size] == '/')
					extension = ft_strnjoin(2, home, &parameter[size]);
			}
		}
	}
	free(home);
	free(logname);
	return (extension);
}
