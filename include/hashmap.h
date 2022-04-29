/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:19:42 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/29 07:50:51 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

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

/*
** Environment variables list
*/

size_t		envp_length(char **envp);
char		*get_key(char *variable);
char		*get_value(char *variable);

/*
** Hashmap initialization
*/

t_hashtable	*create_hashmap(char **variables);
void		populate_hashmap(int type, char **variables);
void		delete_hashmap(int type);
void		print_hashmap(int type);

/*
** Hashmap functions
*/

int			hash(char *key, size_t size);

/*
** Hashmap variable management
*/

void		hash_insert(int type, char *key, char *value);
void		hash_substitute(int type, char *key, char *value);
void		hash_remove(int type, char *key);
int			key_location(char *key);
char		*key_search(int type, char *key);

#endif