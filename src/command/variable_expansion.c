/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:26:12 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 11:39:04 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_variable_expandable(char first_letter);
static char	**expand_variable(t_tkn *tkn, int *pos);
static char	**split_variable_expansion(char	*expansion);
static void	clean_expansion(char **split, char *next);

/*	VARIABLE_EXPANSION
**	------------------
**	DESCRIPTION
**	It expands the variable key preceded by $ into its value.
**	PARAMETERS
**	#1. The token to expand.
**	RETURN VALUES
**	The expanded string, if appliable. NULL if no variable was found.
*/

void	variable_expansion(t_tkn **tkn, int *pos)
{
	char	*prev;
	char	*next;
	char	**expansion_split;
	t_tkn	*last;
	int		i;

	if (!is_variable_expandable((*tkn)->token[(*pos) + 1]))
		return ;
	prev = ft_strndup((*tkn)->token, (*pos)++);
	printf("prev = %s\n", prev);
	expansion_split = expand_variable(*tkn, pos);
	int j = -1;
	while (expansion_split[++j])
		printf("split%d = %s\n", j + 1, expansion_split[j]);
	next = ft_strdup(&(*tkn)->token[*pos]);
	printf("next = %s\n", next);
	last = (*tkn)->next;
	(*tkn)->next = NULL;
	i = 0;
	swap_token(*tkn, ft_strjoin(prev, expansion_split[i]));
	while (expansion_split[++i])
		tkn_add_back(tkn, tkn_create(ft_strdup(expansion_split[i]), 1));
	while ((*tkn)->next)
		(*tkn) = (*tkn)->next;
	free(prev);
	prev = (*tkn)->token;
	swap_token(*tkn, ft_strjoin(prev, next));
	(*pos) = ft_strlen(expansion_split[i]) - 1;
	(*tkn)->next = last;
	clean_expansion(expansion_split, next);
}

static int	is_variable_expandable(char first_letter)
{
	if (ft_isalnum(first_letter))
		return (1);
	if (first_letter == '?')
		return (1);
	return (0);
}

static char	**expand_variable(t_tkn *tkn, int *pos)
{
	char	*expansion;
	char	*key;
	int		i;

	i = 0;
	if (tkn->token[*pos] == '?')
		expansion = ft_itoa(g_data.exit_code);
	else if (ft_isdigit(tkn->token[*pos]))
		expansion = NULL;
	else
	{
		while (ft_isalnum(tkn->token[(*pos) + i]))
			i++;
		key = ft_strndup(&tkn->token[*pos], i--);
		expansion = ft_strdup(key_search(BOTH, key));
		free(key);
	}
	(*pos) = (*pos) + 1 + (i);
	return (split_variable_expansion(expansion));
}

static char	**split_variable_expansion(char	*expansion)
{
	char	**result;

	if (!expansion)
		result = (char **)ft_calloc(1, sizeof(char *));
	else
		result = ft_split(expansion, ' ');
	if (expansion)
		free(expansion);
	return (result);
}

static void	clean_expansion(char **split, char *next)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	if (next)
		free(next);
}
