/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:48:20 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/13 16:13:31 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

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
}	t_hashtable;

typedef struct s_minishell {
	t_hashtable	*envp;
	t_hashtable *local;
}	t_minishell;


/*
**	Global variable for session data
*/

t_minishell g_data;

void	error(int exit_code);

/*
** Hashtable
*/

t_hashtable	*create_hashtable(char **list);
t_hashlist **create_table(size_t list_len, char **list);

/*
** Utilities
*/

size_t	ft_listlen(char **list);

#endif