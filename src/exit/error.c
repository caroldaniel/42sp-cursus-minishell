/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:19:37 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/10 09:24:04 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_minishell(void);

/*	ERROR
**	-----
**	DESCRIPTION
**	The error function directs the program to close all memory previously 
**	allocated to the global struct, prints the appropriate error message on 
**	the standard error file descriptor and exits with the correct code, if
**	necessary. 
**	PARAMETERS
**	#1. A token used to indicate the step of execution in which it stopped;
**	#2. A flag to indicate the correct message to print;
**	#3. The exit code in which it will close upon.
**	RETURN VALUES
**	-
*/

void	error(char *s, int flag, int code)
{
	g_data.exit_code = code;
	if (flag == 1)
		ft_dprintf(2, "%s: Invalid number of arguments\n", s);
	if (flag == 2)
		ft_dprintf(2, "%s\n", s);
	if (flag == -1)
		ft_dprintf(2, "minishell: cd: %s not set\n", s);
	if (flag == -2)
		ft_dprintf(2, "minishell: cd: %s: No such file or directory\n", s);
	if (flag == -3)
		ft_dprintf(2, "minishell: syntax error near unexpected token `%s'\n", s);
	if (flag == -4)
		ft_dprintf(2, "minishell: syntax error near unexpected token `newline'\n");
	if (flag == -5)
		ft_dprintf(2, "minishell: quote missing\n");
	if (flag == -6)
		ft_dprintf(2, "minishell: %s: No such file or directory\n", s);
	if (flag == -7)
		ft_dprintf(2, "minishell: %s: Command not found\n", s);
	if (flag == -8)
		ft_dprintf(2, "minishell: here-document delimited by end-of-file (wanted `%s')\n", s);
	if (flag >= 0)
		exit_minishell();
}

static void	exit_minishell(void)
{
	clear();
	exit(g_data.exit_code);
}
