/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:26:12 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/03 09:26:43 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_variable(char *result, int *pos);
static char	*get_key_value(char *result, int *pos);
static int	is_expandable(char *token, int pos);
static void	flag_switch(int *is_in);

/*	VARIABLE_EXPANSION
**	------------------
**	DESCRIPTION
**	It expands the variable key preceded by $ into its value.
**	PARAMETERS
**	#1. The token to expand.
**	RETURN VALUES
**	The expanded string, if appliable. NULL if no variable was found.
*/

char	*variable_expansion(char *token)
{
	char	*result;
	int		is_in_double;
	int		is_in_single;
	int		pos;

	result = ft_strdup(token);
	is_in_double = 0;
	is_in_single = 0;
	pos = -1;
	while (result[++pos])
	{
		if (result[pos] == '\"')
			flag_switch(&is_in_double);
		else if (result[pos] == '\'')
			flag_switch(&is_in_single);
		else if ((!is_in_single || is_in_double) && result[pos] == '$' && \
			is_expandable(result, pos + 1))
			result = expand_variable(result, &pos);
	}
	return (result);
}

static char	*expand_variable(char *result, int *pos)
{
	char	*prev;
	char	*expansion;
	char	*current;
	char	*prev_result;

	prev = ft_strndup(result, *pos);
	(*pos)++;
	if (ft_isdigit(result[*pos]))
		expansion = NULL;
	else if (result[*pos] == '?')
		expansion = ft_itoa(g_data.exit_code);
	else
		expansion = get_key_value(result, pos);
	(*pos)++;
	current = ft_strjoin(prev, expansion);
	free(prev);
	free(expansion);
	prev_result = result;
	result = ft_strjoin(current, &result[*pos]);
	*pos = ft_strlen(current) - 1;
	free(current);
	free(prev_result);
	return (result);
}

static char	*get_key_value(char *result, int *pos)
{
	char	*value;
	char	*key;
	int		i;

	i = 0;
	while (ft_isalnum(result[(*pos) + i]))
		i++;
	key = ft_strndup(&result[*pos], i);
	value = ft_strdup(key_search(BOTH, key));
	free(key);
	*pos = (*pos) + (i - 1);
	return (value);
}

static int	is_expandable(char *token, int pos)
{
	if (ft_isalnum(token[pos]))
		return (1);
	if (token[pos] == '?')
		return (1);
	return (0);
}

static void	flag_switch(int *is_in)
{
	if (!(*is_in))
		*is_in = 1;
	else
		*is_in = 0;
}
