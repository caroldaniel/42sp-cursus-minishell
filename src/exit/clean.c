/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:58:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/28 14:45:10 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	ERROR
**	-----
**	DESCRIPTION
**	The error function directs the program to close all memory previously 
**	allocated to the global struct, prints the appropriate error message and
**	exits with the correct code. 
**	PARAMETERS
**	#1. A token used to indicate the step of execution in which it stopped;
**	#2. A flag to indicate the correct message to print;
**	#3. The exit code in which it will close upon.
**	RETURN VALUES
**	-
*/

void	clean(void)
{
	if (g_data.vars[ENV])
		delete_hashmap(ENV);
	if (g_data.vars[LOCAL])
		delete_hashmap(LOCAL);
}
