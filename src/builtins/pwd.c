/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:46:39 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/08 12:04:48 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

/*	PWD
**	-------
**	DESCRIPTION
**	Prints the current working directory.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	pwd(void)
{
	char	*pwd;
	pwd = get_pwd();
	printf("%s\n", pwd);
}

/*	GET_PWD
**	-------
**	DESCRIPTION
**	Gets the current working directory.
**	PARAMETERS
**	-
**	RETURN VALUES
**	The NULL terminated, malloc(3) allocated string with the directory path.
*/

char	*get_pwd(void)
{
	char	*buffer;

	buffer = NULL;
	return (getcwd(buffer, 0));
}
