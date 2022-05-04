/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:25:54 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/04 13:26:07 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_tokens(void)
{
	char	**list;
	int		i;

	list = g_data.parser->tokens->list;
	i = -1;
	while (list[++i])
		free(list[i]);
	free(list);
	free(g_data.parser->tokens);
}
