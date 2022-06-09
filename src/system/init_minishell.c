/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:40:35 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 09:29:58 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	INIT_MINISHELL
**	--------------
**	DESCRIPTION
**	This function will first initialize the global structure with the envp 
**	parameter's list (converted into a hashtable), and point all structures that
**	will be used to NULL.
**	PARAMETERS
**	#1. The environment variables list taken from the parent shell.
**	RETURN VALUES
**	-
*/

void	init_minishell(char **variables)
{
	g_data.vars[ENV] = create_hashmap(variables);
	g_data.vars[LOCAL] = create_hashmap(NULL);
	if (variables)
		populate_hashmap(ENV, variables);
	g_data.parser = NULL;
	g_data.cmd = NULL;
	g_data.exit_code = 0;
}
