/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_signals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:51:29 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/10 22:32:30 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_sig(int signal);
static void	parent_sig(int signal);

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
