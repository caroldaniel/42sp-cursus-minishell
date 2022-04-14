# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 09:39:16 by cado-car          #+#    #+#              #
#    Updated: 2022/04/14 14:56:16 by cado-car         ###   ########.fr        #
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

SRC				= main.c \
				error.c \
				create_hashmap.c \
				hash_function.c \
				hash_insert.c \
				envp_to_hashmap.c \
				envp_key_value.c \
				envp_length.c \
				print_env_hash.c \
				open_terminal.c \
				pwd.c

VPATH 			:= $(SRC_PATH)\
				$(SRC_PATH)environment\
				$(SRC_PATH)hashmap\
				$(SRC_PATH)utilities\
				$(SRC_PATH)builtins

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