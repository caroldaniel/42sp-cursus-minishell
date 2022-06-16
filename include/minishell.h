/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:48:20 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 18:18:40 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>

# include "../libft/libft.h"
# include "hashmap.h"
# include "colors.h"
# include "executables.h"
# include "parser.h"

/*
** Struct definition
*/

typedef struct s_minishell {
	t_hashtable	*environ;
	t_parser	*parser;
	t_cmd		*cmd;
	int			exit_code;
}	t_minishell;

/*
** Environment & Local tables enum definition
*/

enum e_type {
	ENV,
	LOCAL,
	BOTH
};

/*
**	Global variable for session data
*/

extern t_minishell	g_data;

/*
** Initialization
*/

void		init_minishell(char **envp);
t_parser	*init_parser(void);
t_tkn		*init_tkn(void);

/*
** System
*/

void		open_terminal(void);
void		change_input_signals(void);

/*
** Program exit functions
*/

void		error(char *s, int flag, int code);
void		clear(void);
void		clear_cmd(void);
void		clear_parser(void);
void		clear_tokens(t_tkn **list);

/*
** Prompt
*/

char		*create_prompt(void);

/*
** Utilities
*/

void		print_envp_hash(void);

/*
** Built-ins
*/

void		ft_exit(void);
int			ft_echo(char **exec);
int			ft_export(char **exec);
int			ft_set(char **exec);
int			ft_unset(char **exec);
int			ft_env(char **exec);
int			ft_cd(char **exec);
int			ft_pwd(void);
char		*get_pwd(void);

#endif