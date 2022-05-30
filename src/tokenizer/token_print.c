/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:49:08 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/30 07:43:08 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*lexemas_print(int type);

void	token_print(void)
{
	t_tkn	*token;
	t_tkn	*commands;
	t_tkn	*redirects;
	t_cmd	*node;

	token = g_data.parser->tokens;
	while (token)
	{
		printf("[TOKEN]  %s\t\t[LEXEMA]  %s\n", token->token, \
			lexemas_print(token->lexema));
		token = token->next;
	}
	node = g_data.cmd;
	while (node)
	{
		printf("\nNEW COMMAND\n");
		commands = node->commands;
		printf("\n\nCOMMANDS FOR EXECVE\n");
		while (commands)
		{
			printf("[TOKEN]  %s\t\t[LEXEMA]  %s\n", commands->token,
				lexemas_print(commands->lexema));
			commands = commands->next;
		}
		redirects = node->redirects;
		printf("\n\nREDIRECTS\n");
		while (redirects)
		{
			printf("[TOKEN]  %s\t\t[LEXEMA]  %s\n", redirects->token,
				lexemas_print(redirects->lexema));
			redirects = redirects->next;
		}
		node = node->next;
	}
}

static char	*lexemas_print(int type)
{
	if (type == WORD)
		return ("WORD");
	if (type == ASSIGN_WORD)
		return ("ASSIGN_WORD");
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
