/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:40:35 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 19:27:07 by cado-car         ###   ########.fr       */
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

void	init_minishell(char **envp)
{
	g_data.environ = init_hashtable();
	populate_hashmap(envp);
	envp_create();
	g_data.parser = NULL;
	g_data.cmd = NULL;
	g_data.exit_code = 0;
}
