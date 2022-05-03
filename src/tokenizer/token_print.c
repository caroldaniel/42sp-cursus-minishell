/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:49:08 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/03 20:53:43 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_print(void)
{
	size_t	i;

	i = 0;
	while (i < g_data.parser->tokens->count)
	{
		printf("[TOKEN %2ld] |%s|\n", i + 1, g_data.parser->tokens->list[i]);
		i++;
	}
}
