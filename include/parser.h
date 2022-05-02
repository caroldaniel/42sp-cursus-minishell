/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/02 16:48:38 by cado-car         ###   ########.fr       */
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

# define METACHARS	"|<>"

/*
** Parser Functions
*/

void		tokenizer(void);
t_tokens	*get_tokens(void);

#endif