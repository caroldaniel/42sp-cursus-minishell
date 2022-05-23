/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 08:52:45 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/23 10:20:36 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_analysis(void)
{
	char	**token;
	int		i;

	token = g_data.parser->tokens->list;
	i = -1;
	while (token[++i])
	{
		if (!syntax_pipe_and_or_if(i))
			break ;
		else if (!syntax_io_redirect(i))
			break ;
		else if (!syntax_and(i))
			break ;
		else if (!syntax_quote(i))
			break ;
	}
	return (1);
}
