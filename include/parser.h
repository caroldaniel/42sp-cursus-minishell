/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/04 09:40:52 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/*
** Line Struct
*/

typedef struct s_tokens
{
	char	**list;
	size_t	count;
}	t_tokens;

/*
** Line Struct
*/

typedef struct s_parser
{
	char		*input;
	t_tokens	*tokens;
}	t_parser;

/*
** Constants definitions
*/

# define METACHAR	"|<>&"
# define METACHARS	"|<>& "

/*
** Tokenizer Functions
*/

void	tokenizer(void);
size_t	token_count(const char *input);
char	**token_split(const char *input, size_t size);
int		is_new_token(const char *input, size_t index, size_t prev);
void	token_print(void);

#endif