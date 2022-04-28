/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_location.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:57:30 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/28 15:24:23 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	KEY_LOCATION
**	------------
**	Checks which hashtable the variable is stored 
**	PARAMETERS
**	#1. The variable key 
**	RETURN VALUES
**	0 for Environment table, 1 for Local table, or -1 for not found.
*/

int	key_location(char *key)
{	
	if (key_search(ENV, key))
		return (ENV);
	if (key_search(LOCAL, key))
		return (LOCAL);
	return (-1);
}
