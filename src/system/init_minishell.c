/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:40:35 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/02 15:14:18 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_minishell(char **variables)
{
	g_data.vars[ENV] = create_hashmap(variables);
	g_data.vars[LOCAL] = create_hashmap(NULL);
	if (variables)
		populate_hashmap(ENV, variables);
	g_data.parser = init_parser();
}
