/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:19:42 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/16 17:02:34 by cado-car         ###   ########.fr       */
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
** Hashmap functions prototypes
*/

t_hashtable	*create_hashtable(char **variables);
int			hash(char *key, size_t size);
void		hash_insert(t_hashtable **table, char *variable);
char		*hash_search(t_hashtable *table, char *key);


#endif