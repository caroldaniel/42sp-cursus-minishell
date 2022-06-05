/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:04:44 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/05 20:36:18 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	QUOTE_EXPANSION
**	---------------
**	DESCRIPTION
**	It expands the token in which there are quotation marks (either "" or ''), 
**	as well as any possible variables ($VAR) within "".
**	PARAMETERS
**	#1. The token to expand.
**	RETURN VALUES
**	The expanded string, if appliable. NULL if no quotation was found.
*/

void	quote_expansion(t_tkn **tkn, int *pos, char quote)
{
	char	*prev;
	char	*expansion;
	char	*current;
	char	*prev_result;

	prev = ft_strndup((*tkn)->token, *pos);
	(*pos)++;
	while ((*tkn)->token[(*pos)] && (*tkn)->token[(*pos)] != quote)
	{
		if ((*tkn)->token[(*pos)] == '$')
			variable_expansion(tkn, pos);
		(*pos)++;
	}
	expansion = ft_substr((*tkn)->token, *pos, len);
	current = ft_strjoin(prev, expansion);
	free(prev);
	free(expansion);
	prev_result = token;
	token = ft_strjoin(current, &token[(*pos) + len + 1]);
	*pos = ft_strlen(current) - 1;
	free(current);
	free(prev_result);
	return (token);
}
