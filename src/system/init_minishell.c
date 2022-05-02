/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:40:35 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/02 09:31:46 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_line(void);

void	init_minishell(char **variables)
{
	g_data.vars[ENV] = create_hashmap(variables);
	g_data.vars[LOCAL] = create_hashmap(NULL);
	if (variables)
		populate_hashmap(ENV, variables);
	init_line();
}

static void	init_line(void)
{
	g_data.line = malloc(sizeof(t_line));
	if (!g_data.line)
		error(NULL, 1, 1);
	g_data.line->input = NULL;
}
