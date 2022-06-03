/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/03 14:28:39 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

enum e_lexemas {
	WORD,
	ASSIGN_WORD,
	LESS,
	DLESS,
	GREAT,
	DGREAT,
	ERROR,
	AND,
	PIPE,
	AND_IF,
	OR_IF
};

/*
** Token and List Structs
*/

typedef struct s_tkn
{
	char			*token;
	int				lexema;
	struct s_tkn	*next;
}	t_tkn;

/*
** Parser Struct
*/

typedef struct s_parser
{
	char		*input;
	t_tkn		*tokens;
}	t_parser;

/*
** Command Struct
*/

typedef struct s_cmd
{
	t_tkn			*commands;
	t_tkn			*redirects;
	char			**exec;
	int				endpoint;
	int				fd_out;
	int				fd_in;
	int				pid;
	struct s_cmd	*next;
}	t_cmd;

/*
** Constants definitions
*/

# define METACHAR	"|<>&"
# define METACHARS	"|<>& "

/*
** Tokenizer Functions
*/

void	tokenizer(void);
void	token_split(const char *input);
int		is_new_token(const char *input, size_t index, size_t prev);
void	token_print(void);

/*
** Token List Utils
*/

t_tkn	*tkn_create(char *token);
t_tkn	*tkn_dup(t_tkn *original);
void	tkn_remove(t_tkn **list, char *token);
void	tkn_add_back(t_tkn **list, t_tkn *token);
int		lexical_analysis(char *token);

/*
** Syntax Analysis
*/

int		syntax_analysis(void);
int		syntax_pipe_and_or_if(t_tkn *tkn, int pos);
int		syntax_io_redirect(t_tkn *tkn);
int		syntax_quote(t_tkn *tkn);
int		syntax_and(t_tkn *tkn);

/*
** Syntax Analysis
*/

t_cmd	*cmd_create(void);
void	cmd_add_back(t_cmd *node);
void	cmd_add_front(t_cmd *node);

/*
** Command table
*/

void	command_table(void);
void	command_expansion(void);
char	*single_quote_expansion(char *token);
char	*double_quote_expansion(char *token);
#endif