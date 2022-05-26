/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 08:52:45 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 11:36:39 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_analysis(void)
{
	t_tkn	*token;
	int		pos;

	token = g_data.parser->tokens;
	pos = 0;
	while (token)
	{
		if (!syntax_pipe_and_or_if(token, pos))
			return (0);
		else if (!syntax_io_redirect(token))
			return (0);
		else if (!syntax_and(token))
			return (0);
		else if (!syntax_quote(token))
			return (0);
		token = token->next;
		pos++;
	}
	return (1);
}
