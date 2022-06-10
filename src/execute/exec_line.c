/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:08:52 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/10 10:35:34 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	EXEC_LINE
**	---------
**	DESCRIPTION
**	It's a workflow for the execution of all commands passed by the user through
**	the prompt line. It first opens all the pipes, and then it reads and applies
**	the redirects and heredocs (since they have precedence over pipes). Lastly, 
**	it executes the commands by priority indentation.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	exec_line(void)
{
	open_pipes();
	define_std_fileno();
	exec_cmd();
}
