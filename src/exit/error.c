/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:19:37 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/02 09:05:28 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	ERROR
**	-----
**	DESCRIPTION
**	The error function directs the program to close all memory previously 
**	allocated to the global struct, prints the appropriate error message and
**	exits with the correct code. 
**	PARAMETERS
**	#1. A token used to indicate the step of execution in which it stopped;
**	#2. A flag to indicate the correct message to print;
**	#3. The exit code in which it will close upon.
**	RETURN VALUES
**	-
*/

void	error(char *token, int flag, int code)
{
	g_data.exit_code = code;
	if (flag == 1)
		printf("%s: Invalid number of arguments\n", token);
	if (flag == -1)
		printf("minishell: cd: %s not set\n", token);
	if (flag == -2)
		printf("minishell: cd: %s: No such file or directory\n", token);
	if (flag > 0)
	{
		clean();
		exit(g_data.exit_code);
	}
}
