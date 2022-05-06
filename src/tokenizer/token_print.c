/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:49:08 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/06 10:13:04 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*lexemas_print(int type);

void	token_print(void)
{
	size_t	i;

	i = 0;
	while (i < g_data.parser->tokens->count)
	{
		printf("%2ld - [TOKEN]  %s \t\t[LEXEMA]  %s\n", i + 1,
			g_data.parser->tokens->list[i],
			lexemas_print(g_data.parser->tokens->lexemas[i]));
		i++;
	}
}

static char	*lexemas_print(int type)
{
	if (type == WORD)
		return ("WORD");
	if (type == ASSIGNMENT_WORD)
		return ("ASSIGNMENT_WORD");
	if (type == AND_IF)
		return ("AND_IF");
	if (type == OR_IF)
		return ("OR_IF");
	if (type == LESS)
		return ("LESS");
	if (type == DLESS)
		return ("DLESS");
	if (type == GREAT)
		return ("GREAT");
	if (type == DGREAT)
		return ("DGREAT");
	if (type == PIPE)
		return ("PIPE");
	if (type == AND)
		return ("AND");
	if (type == ERROR)
		return ("ERROR");
	return (NULL);
}
	