#include "minishell.h"

static char	*expand_single_quote(char *result, int *pos);
static void	flag_switch(int *is_in);


char	*single_quote_expansion(char *token)
{
	char	*result;
	int		is_in_double;
	int		pos;

	result = ft_strdup(token);
	is_in_double = 0;
	pos = -1;
	while (result[++pos])
	{
		if (result[pos] == '\"')
			flag_switch(&is_in_double);
		else if (!is_in_double && result[pos] == '\'')
			result = expand_single_quote(result, &pos);
	}
	return (result);
}

static char	*expand_single_quote(char *result, int *pos)
{
	char	*prev;
	char	*expansion;
	char	*current;
	char	*prev_result;
    int     start;

	prev = ft_strndup(result, *pos);
    (*pos)++;
	start = *pos;
    while (result[*pos] != '\'')
        (*pos)++;
    expansion = ft_substr(result, start, *pos - start);
	printf("expansion %s\n", expansion);
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

static void	flag_switch(int *is_in)
{
	if (!(*is_in))
		*is_in = 1;
	else
		*is_in = 0;
}
