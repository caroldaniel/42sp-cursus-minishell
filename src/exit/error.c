/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:19:37 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/04 14:58:57 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_error(char *s, int flag);
static void	syntax_error(char *s, int flag);
static void	redirect_error(char *s, int flag);
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
	if (flag < 0 && flag > -20)
		exec_error(s, flag);
	if (flag <= -20 && flag > -50)
		syntax_error(s, flag);
	if (flag <= -50)
		redirect_error(s, flag);
	if (flag == 1)
		ft_dprintf(2, "%s\n", s);
	if (flag == 2)
		ft_dprintf(2, "%s: Invalid number of arguments\n", s);
	if (flag == 3)
		ft_dprintf(2, "\n");
	if (flag >= 0)
		exit_minishell();
}

static void	exec_error(char *s, int flag)
{
	if (flag == -1)
		ft_dprintf(2, "minishell: cd: %s not set\n", s);
	if (flag == -2)
		ft_dprintf(2, "minishell: cd: %s: No such file or directory\n", s);
	if (flag == -3)
		ft_dprintf(2, "minishell: cd: %s not set\n", s);
	if (flag == -4)
		ft_dprintf(2, "minishell: %s: too many arguments\n", s);
	if (flag == -5)
		ft_dprintf(2, "%s: Command not found\n", s);
	if (flag == -6)
		ft_dprintf(2, "minishell: export: %s: not a valid identifier\n", s);
}

static void	syntax_error(char *s, int flag)
{
	if (flag == -20)
		ft_dprintf(2, "minishell: syntax error near unexpected token \
`%s'\n", s);
	if (flag == -21)
		ft_dprintf(2, "minishell: syntax error near unexpected token \
`newline'\n");
	if (flag == -22)
		ft_dprintf(2, "minishell: quote missing\n");
	if (flag == -23)
		ft_dprintf(2, "minishell: closing parenthesis missing\n");
}

static void	redirect_error(char *s, int flag)
{
	if (flag == -50)
		ft_dprintf(2, "minishell: %s: Permission denied\n", s);
	if (flag == -51)
		ft_dprintf(2, "minishell: %s: No such file or directory\n", s);
	if (flag == -52)
		ft_dprintf(2, "minishell: warning: here-document delimited by \
end-of-file (wanted `%s')\n", s);
	if (flag == -53)
		ft_dprintf(2, "Quit\n");
	if (flag == -54)
		ft_dprintf(2, "\n");
}

static void	exit_minishell(void)
{
	clear();
	exit(g_data.exit_code);
}
