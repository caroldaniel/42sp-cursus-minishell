/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:46:46 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 09:19:48 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	CLEAR_PARSER
**	------------
**	DESCRIPTION
**	The clear_parser function will free the entire t_parser struct inside the 
**	main global structure, clearing the token's list and the input string. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/


void	clear_parser(void)
{
	if (!g_data.parser)
		return ;
	if (g_data.parser->input)
		free(g_data.parser->input);
	if (g_data.parser->tokens)
		clear_tokens(&g_data.parser->tokens);
	free(g_data.parser);
	g_data.parser = NULL;
}
