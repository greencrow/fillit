# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/27 16:07:06 by svigouro          #+#    #+#              #
#    Updated: 2017/05/03 14:31:24 by svigouro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re
.SUFFIXES:

NAME 	=	fillit
L_NAME	=	ft

SRC_DIR	=	srcs
IN_DIR 	= 	includes
L_DIR 	= 	libft

RAW_SRC = 	main.c \
			ft_print_error.c \
			ft_check_file.c
OBJ 	= 	$(RAW_SRC:%.c=%.o)
SRC		=	$(addprefix $(SRC_DIR)/,$(RAW_SRC))

CC 		= 	gcc
CFLAGS 	= 	-Wall -Wextra -Werror

GREY    = 	$'\x1b[30m
RED     = 	$'\x1b[31m
GREEN   = 	$'\x1b[32m
YELLOW  = 	$'\x1b[33m
BLUE    = 	$'\x1b[34m
PURPLE  = 	$'\x1b[35m
CYAN    = 	$'\x1b[36m
WHITE   = 	$'\x1b[37m
BOLD    = 	$'\x1b[1m
UNDER   = 	$'\x1b[4m
REV     = 	$'\x1b[7m
END     = 	$'\x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(L_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(L_DIR) -l$(L_NAME)
	@echo "${GREEN}➤  ${BOLD}$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$((L_DIR) -l$(L_NAME)${END}"

$(OBJ):
	@$(CC) $(CFLAGS) -I $(IN_DIR) -c $(SRC)
	@echo "${GREEN}[  Compiling $(NAME)  ]${END}"
	@echo "${GREEN}➤  ${BOLD}$(CC) $(CFLAGS) -I $(IN_DIR) -c $(SRC)${END}"

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(L_DIR)
	@echo "${RED}[  Cleaning $(NAME)  ]${END}"
	@echo "${RED}➤  ${BOLD}rm -f $(OBJ)${END}"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(L_DIR)
	@echo "${RED}➤  ${BOLD}rm -f $(NAME)${END}"

re: fclean all
