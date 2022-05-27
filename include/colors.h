/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:31:20 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 15:48:04 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	COLORS_H
# define COLORS_H

# include "minishell.h"

# define ESC_BLACK "\001\033[0;30m"
# define ESC_BOLD_BLACK "\001\033[1;30m\002"
# define ESC_RED "\001\033[0;31m\002"
# define ESC_BOLD_RED "\001\033[1;31m\002"
# define ESC_GREEN "\001\033[0;32m\002"
# define ESC_BOLD_GREEN "\001\033[1;32m\002"
# define ESC_YELLOW "\001\033[0;33m\002"
# define ESC_BOLD_YELLOW "\001\033[1;33m\002"
# define ESC_BLUE "\001\033[0;34m\002"
# define ESC_BOLD_BLUE "\001\033[1;34m\002"
# define ESC_PURPLE "\001\033[0;35m\002"
# define ESC_BOLD_PURPLE "\001\033[1;35m\002"
# define ESC_CYAN "\001\033[0;36m\002"
# define ESC_BOLD_CYAN "\001\033[1;36m\002"
# define ESC_WHITE "\001\033[0;37m\002"
# define ESC_BOLD_WHITE "\001\033[1;37m\002"
# define ESC_RESET_COLOR "\001\033[0m\002"

#endif