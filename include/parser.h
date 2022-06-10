/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/10 11:34:31 by cado-car         ###   ########.fr       */
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
	int				endpoint;
	char			**exec;
	char			*exec_path;
	int				fd_out;
	int				fd_in;
	int				fd_pipe[2];
	int				errnb;
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

t_tkn	*tkn_create(char *token, int flag);
t_tkn	*tkn_dup(t_tkn *original);
void	tkn_remove(t_tkn **list, char *token);
void	tkn_add_back(t_tkn **list, t_tkn *token);
size_t	tkn_len(t_tkn *tkn);
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

void	swap_token(t_tkn *tkn, char	*new_token);
void	command_table(void);
void	command_expansion(void);
void	command_list(void);
void	tilde_expansion(t_tkn **tkn, int *pos);
void	variable_expansion(t_tkn **tkn, int *pos);
void	quote_expansion(t_tkn **tkn, int *pos, char quote);

#endif