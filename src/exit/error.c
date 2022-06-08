/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:19:37 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/08 10:56:50 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_minishell(void);

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
	if (flag == 2)
		printf("%s\n", token);
	if (flag == -1)
		printf("minishell: cd: %s not set\n", token);
	if (flag == -2)
		printf("minishell: cd: %s: No such file or directory\n", token);
	if (flag == -3)
		printf("minishell: syntax error near unexpected token `%s'\n", token);
	if (flag == -4)
		printf("minishell: syntax error near unexpected token `newline'\n");
	if (flag == -5)
		printf("minishell: quote missing\n");
	if (flag == -6)
		printf("minishell: %s: No such file or directory\n", token);
	if (flag == -7)
		printf("minishell: %s: Command not found\n", token);
	if (flag >= 0)
		exit_minishell();
}

static void	exit_minishell(void)
{
	clear();
	exit(g_data.exit_code);
}
