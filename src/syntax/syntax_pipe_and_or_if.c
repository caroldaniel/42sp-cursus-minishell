/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_pipe_and_or_if.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:05:19 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/27 10:19:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_pipe_and_or_if(t_tkn *tkn, int pos)
{
	if (tkn->lexema == PIPE || tkn->lexema == AND_IF || tkn->lexema == OR_IF)
	{
		if (pos == 0 || !tkn->next)
		{
			error(tkn->token, -3, 2);
			return (0);
		}
	}
	return (1);
}
