/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:46:46 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 11:06:01 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_parser(void)
{
	if (g_data.parser->input)
		free(g_data.parser->input);
	if (g_data.parser->tokens)
		clear_tokens();
	if (g_data.parser->cmd)
		clear_cmd();
	free(g_data.parser);
}
