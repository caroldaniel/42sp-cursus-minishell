/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:48:20 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/15 13:57:49 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

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
}	t_minishell;



/*
**	Global variable for session data
*/

t_minishell	g_data;

/*
** Main
*/

void		open_terminal(void);
void		error(int exit_code);

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

void		print_envp_hash(char **envp);

/*
** Built-ins
*/

char		*pwd(void);

#endif