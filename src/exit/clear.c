/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:58:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 09:17:07 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	CLEAR
**	-----
**	DESCRIPTION
**	The clear function will free all structures allocated inside the main global 
**	structure of the program. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	clear(void)
{
	if (g_data.vars[ENV])
		delete_hashmap(ENV);
	if (g_data.vars[LOCAL])
		delete_hashmap(LOCAL);
	if (g_data.parser)
		clear_parser();
	if (g_data.cmd)
		clear_cmd();
	rl_clear_history();
}
