/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:48:20 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/28 10:23:49 by cado-car         ###   ########.fr       */
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
	t_hashtable	*envp;
	t_hashtable	*local;
	int			exit_code;
}	t_minishell;

/*
**	Global variable for session data
*/

extern t_minishell	g_data;

/*
** System
*/

void		open_terminal(void);
void		error(char *token, int flag, int code);
void		change_signals(void);

/*
** Prompt
*/

char		*create_prompt(void);

/*
** Environment
*/

void		envp_to_hashmap(t_hashtable **table, char **variables);
size_t		envp_length(char **envp);
char		*get_key(char *variable);
char		*get_value(char *variable);

/*
** Utilities
*/

void		print_envp_hash(void);

/*
** Built-ins
*/

char		*pwd(void);

#endif