/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:03:17 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 10:11:03 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tkn	*tkn_create(char *token)
{
	t_tkn	*tkn;

	tkn = malloc(sizeof(t_tkn));
	if (!tkn)
		error(NULL, 0, 12);
	tkn->token = token;
	tkn->lexema = lexical_analysis(token);
	tkn->next = NULL;
	return (tkn);
}
