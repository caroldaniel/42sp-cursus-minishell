/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:58:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 18:44:13 by cado-car         ###   ########.fr       */
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
	if (g_data.environ)
		delete_hashmap();
	if (g_data.parser)
		clear_parser();
	if (g_data.cmd)
		clear_cmd();
	rl_clear_history();
}
