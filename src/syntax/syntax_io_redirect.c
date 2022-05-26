/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:05:44 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 11:38:30 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_io_redirect(t_tkn *tkn)
{
	if (tkn->lexema == LESS || tkn->lexema == DLESS || tkn->lexema == GREAT || \
		tkn->lexema == DGREAT)
	{
		if (!tkn->next)
		{
			error(NULL, -4, 2);
			return (0);
		}
		else if (tkn->next->lexema != WORD && tkn->next->lexema != ASSIGN_WORD)
		{
			error(tkn->next->token, -3, 2);
			return (0);
		}
	}
	return (1);
}
