/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_signals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:51:29 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/17 00:15:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_sig(int signal);
static void	parent_sig(int signal);

/*	FET_HEREDOC_SIGNAL
**	------------------
**	DESCRIPTION
**	It changes the default signals received by specific shortcuts when executing
**	the get_heredoc function, to avoid that these signals will respond to the
**	parent shell, instead of the current. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	get_heredoc_child_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, child_sig);
}

static void	child_sig(int signal)
{
	if (signal == SIGINT)
		error(NULL, 0, 0);
}

void	get_heredoc_parent_signal(void)
{
	signal(SIGQUIT, parent_sig);
	signal(SIGINT, parent_sig);
}

static void	parent_sig(int signal)
{
	if (signal == SIGINT)
		printf("\n");
}
