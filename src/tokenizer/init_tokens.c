/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:43:51 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/06 08:35:27 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	*init_tokens(void)
{
	t_tokens	*tokens;

	tokens = malloc(sizeof(t_tokens));
	if (!tokens)
		error(NULL, 0, 12);
	tokens->list = NULL;
	tokens->lexemas = NULL;
	return (tokens);
}
