/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:21:14 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/16 21:45:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	reprompt(int signal);

void	change_signals(void)
{
	signal(SIGINT, reprompt);
	signal(SIGQUIT, SIG_IGN);
}

static void	reprompt(int signal)
{
	(void)signal;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
