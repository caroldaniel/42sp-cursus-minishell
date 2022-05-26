/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:25:54 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 11:12:29 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_tokens(void)
{
	t_tkn	*curr;
	t_tkn	*tmp;

	curr = g_data.parser->tokens;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp->token);
		free(tmp);
	}
	g_data.parser->tokens = NULL;
}
