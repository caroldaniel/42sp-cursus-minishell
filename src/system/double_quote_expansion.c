#include "minishell.h"

static char	*expand_double_quote(char *result, int *pos);

char	*double_quote_expansion(char *token)
{
	char	*result;
	int		pos;

	result = ft_strdup(token);
	pos = -1;
	while (result[++pos])
	{
		if (result[pos] == '\"')
			result = expand_double_quote(result, &pos);
	}
	return (result);
}

static char	*expand_double_quote(char *result, int *pos)
{
	char	*prev;
	char	*expansion;
	char	*current;
	char	*prev_result;
    int     start;

	prev = ft_strndup(result, *pos);
    (*pos)++;
	start = *pos;
    while (result[*pos] != '\"')
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
