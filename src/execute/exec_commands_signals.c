/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands_signals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:48:12 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/14 21:50:54 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	quit_process(int signal);
static void	interrupt_process(int signal);

/*	EXEC_COMMANDS_SIGNALS
**	---------------------
**	DESCRIPTION
**	It changes the default signals received by specific shortcuts when executing
**	the exec_commands function, to avoid that these signals will respond to the
**	parent shell, instead of the current. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	exec_commands_signals(void)
{
	signal(SIGINT, interrupt_process);
	signal(SIGQUIT, quit_process);
}

static void	quit_process(int signal)
{
	(void)signal;
	error(NULL, -9, 131);
}

static void	interrupt_process(int signal)
{
	(void)signal;
	error(NULL, -11, 130);
}
