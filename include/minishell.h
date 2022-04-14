/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:48:20 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/14 13:45:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

/*
** Structs definitions
*/

typedef struct s_hashlist {
	char				*key;
	char				*value;
	struct s_hashlist	*next;
}	t_hashlist;

typedef struct s_hashtable {
	t_hashlist	**list;
	size_t		size;
	size_t		count;
}	t_hashtable;

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
** Hashtable
*/

t_hashtable	*create_hashtable(char **variables);
void		envp_to_hashmap(t_hashtable **table, char **variables);
char		*get_key(char *variable);
char		*get_value(char *variable);
int			hash(char *key, size_t size);
void		hash_insert(t_hashtable **table, char *variable);

/*
** Utilities
*/

size_t		ft_listlen(char **list);
void		print_envp_hash(char **envp);

/*
** Built-ins
*/

char		*get_pwd(void);

#endif