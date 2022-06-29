/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:03:43 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/24 10:38:03 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_wildcard(t_dir **dir, t_tkn **tkn, int *pos);

void	wildcard_expansion(t_tkn **tkn, int *pos)
{
	t_dir	*dir;
	char	*prev;	
	int		i;

	i = 0;
	dir = dir_populate_list("./");
	while ((*tkn)->token)
	{
		if ((*tkn)->token[i] == '$')
			variable_expansion(tkn, &i);
		else if ((*tkn)->token[i] == '\'' || (*tkn)->token[i] == '\"')
			quote_expansion(tkn, &i, (*tkn)->token[i]);
		else if ((*tkn)->token[i] == '*')
			expand_wildcard(&dir, tkn, &i);
		i++;
	}
}

static void	expand_wildcard(t_dir **dir, t_tkn **tkn, int *pos)
{
	t_dir	*tmp;
	char	*prev;

	prev = NULL;
	if (*pos > 0)
		prev = ft_strndup((*tkn)->token, *pos);
	tmp = *dir;
	while (tmp)
	{
		if (ft_strncmp(tmp->file, (*tkn)->token, ft_strlen(tmp->file)))
			dir_remove(dir, tmp->id);
		tmp = tmp->next;
	}
}
