/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/24 21:53:51 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

enum e_lexemas {
	WORD,
	ASSIGNMENT_WORD,
	AND_IF,
	OR_IF,
	LESS,
	DLESS,
	GREAT,
	DGREAT,
	PIPE,
	AND,
	ERROR
};

/*
** Token Struct
*/

typedef struct s_tokens
{
	char	**list;
	int		*lexemas;
	size_t	count;
}	t_tokens;

/*
** Command Struct
*/

typedef struct s_cmd
{
	char			**words;
	char			**redirects;
	char			**here_docs;
	int				pipes;
	int				fd_out;
	int				fd_in;
	int				pid;
	struct s_cmd	*next;
}	t_cmd;

/*
** Parser Struct
*/

typedef struct s_parser
{
	char		*input;
	t_tokens	*tokens;
	t_cmd		*cmd;
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
int		*lexical_analysis(char **token, int size);
void	token_print(void);

/*
** Syntax Analysis
*/

int		syntax_analysis(void);
int		syntax_pipe_and_or_if(int pos);
int		syntax_io_redirect(int pos);
int		syntax_quote(int pos);
int		syntax_and(int pos);

/*
** Syntax Analysis
*/

t_cmd	*cmd_create(void);
void	cmd_add_back(t_cmd *node);
void	cmd_add_front(t_cmd *node);

#endif