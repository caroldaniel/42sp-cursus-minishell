/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:46:31 by cado-car          #+#    #+#             */
/*   Updated: 2022/04/29 16:34:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_data;

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1 && argv)
		error(argv[0], 1, 1);
	init_minishell(envp);
	// open_terminal();

	char *cmd = "..";
	pwd();
	printf("command = '%s'\n", cmd);
	cd(".");
	pwd();
	printf("%s=%s\n", "OLDPWD", key_search(BOTH, "OLDPWD"));
	printf("%s=%s\n", "PWD", key_search(BOTH, "PWD"));

	return (0);
}
