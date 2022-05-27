/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:51:16 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 12:35:47 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tkn	*tkn_dup(t_tkn *original)
{
	t_tkn	*tkn;

	tkn = malloc(sizeof(t_tkn));
	if (!tkn)
		error(NULL, 0, 12);
	tkn->token = ft_strdup(original->token);
	tkn->lexema = original->lexema;
	tkn->next = NULL;
	return (tkn);
}
