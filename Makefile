# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 09:39:16 by cado-car          #+#    #+#              #
#    Updated: 2022/05/02 08:45:34 by cado-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell
LIBFT			= libft.a

#compilation
CC 				= gcc
CF 				= -Wall -Wextra -Werror
CFI 			= -I $(INCLUDE)
CREADLINE		= -lreadline

LIBFT_PATH 		= ./libft/
SRC_PATH 		= ./src/
OBJ_PATH		= ./obj/
INCLUDE 		= ./include/

SRC				= main.c\
				pwd.c\
				export.c\
				cd.c\
				echo.c\
				env.c\
				set.c\
				unset.c\
				clean.c\
				error.c\
				create_hashmap.c\
				delete_hashmap.c\
				populate_hashmap.c\
				print_hashmap.c\
				envp_key_value.c\
				envp_length.c\
				hash_insert.c\
				hash_remove.c\
				hash_substitute.c\
				hash.c\
				key_location.c\
				key_search.c\
				change_signals.c\
				create_prompt.c\
				init_minishell.c\
				open_terminal.c\
				tilde_expansion.c

VPATH 			:= $(SRC_PATH)\
				$(SRC_PATH)builtins\
				$(SRC_PATH)exit\
				$(SRC_PATH)hashmap\
				$(SRC_PATH)system\

OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))

#common commands
RM 				= rm -rf

#rules
$(OBJ_PATH)%.o: %.c
				@printf "\n$(CY)Generating object...$(RC)\n"
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -c $< -o $@
				@printf "$(GR)Object ready!$(RC)"

$(NAME):		$(OBJ)
				@printf "\n$(CY)Generating libft...$(RC)\n"
				make -C $(LIBFT_PATH) $(LIBFT)
				@printf "\n$(CY)Generating minishell executable...$(RC)\n"
				$(CC) $(CF) -I $(INCLUDE) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft $(CREADLINE)
				@printf "$(GR)Done!$(RC)\n\n"

all:			$(NAME)

re:				fclean all

clean:
				make -C $(LIBFT_PATH) clean
				$(RM) $(OBJ) $(OBJDIR)
				@printf "$(RE)minishell objects removed!$(RC)\n\n"

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)
				@printf "$(RE)Executables removed!$(RC)\n\n"

install:		
				sudo apt-get install libreadline-dev
				@printf "$(GR)All dependencies ready!$(RC)\n\n"

.PHONY:			all clean fclean re bonus rebonus

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m