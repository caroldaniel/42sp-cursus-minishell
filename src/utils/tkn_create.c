/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:03:17 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/04 20:55:44 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tkn	*tkn_create(char *token, int flag)
{
	t_tkn	*tkn;

	tkn = malloc(sizeof(t_tkn));
	if (!tkn)
		error(NULL, 0, 12);
	tkn->token = token;
	if (!flag)
		tkn->lexema = lexical_analysis(token);
	else
		tkn->lexema = WORD;
	tkn->next = NULL;
	return (tkn);
}
