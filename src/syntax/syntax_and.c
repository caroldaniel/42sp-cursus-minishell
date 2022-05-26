/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:06:36 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 11:36:01 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_and(t_tkn *tkn)
{
	if (tkn->lexema == AND)
	{
		error(tkn->token, -3, 2);
		return (0);
	}
	return (1);
}