/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:46:39 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/29 11:36:56 by cado-car         ###   ########.fr       */
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
