/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:48:20 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/02 14:34:11 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# include "../libft/libft.h"
# include "hashmap.h"
# include "colors.h"
# include "executables.h"
# include "parser.h"

/*
** Struct definition
*/

typedef struct s_minishell {
	t_hashtable	*vars[2];
	t_line		*line;
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

void		init_minishell(char **variables);
t_line		*init_line(void);

/*
** System
*/

void		open_terminal(void);
void		change_input_signals(void);
char		*tilde_expansion(char *parameter);

/*
** Program exit functions
*/

void		error(char *token, int flag, int code);
void		clear(void);
void		clear_line(void);

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

char		*get_pwd(void);
void		pwd(void);
void		cd(char *parameter);
void		export(char *key, char *value);
void		set(char *key, char *value);
void		unset(char *key);
void		echo(char *flags, char **parameter);
void		env(void);

#endif