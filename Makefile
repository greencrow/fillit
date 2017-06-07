# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/17 15:34:33 by laranda           #+#    #+#              #
#    Updated: 2017/06/06 18:34:16 by svigouro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re
.SUFFIXES:

NAME 	= 	fillit
L_NAME 	= 	ft

L_DIR 	= 	libft

SRC = 	\
	  		main_fillit.c\
	  		helpers.c\
	  		read_input.c\
	  		check_input.c\
	 		build_tetri.c\
	  		list.c\
	  		solve_tetri.c\
	  		print_solution.c
OBJ 	= 	$(SRC:.c=.o)

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
	@$(CC) $(CFLAGS) $(OBJ) -L $(L_DIR) -l$(L_NAME) -o $(NAME)
	@echo "${GREEN}➤  ${BOLD}$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$((L_DIR) -l$(L_NAME)${END}"

$(OBJ):
	@$(CC) $(CFLAGS) -c $(SRC)
	@echo "${GREEN}[  Compiling $(NAME)  ]${END}"
	@echo "${GREEN}➤  ${BOLD}$(CC) $(CFLAGS) -I $(IN_DIR) -c $(SRC)${END}"

clean:
	@$(MAKE) -C libft clean
	@rm -f $(OBJ)
	@echo "${RED}[  Cleaning $(NAME)  ]${END}"
	@echo "${RED}➤  ${BOLD}rm -f $(OBJ)${END}"

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)
	@echo "${RED}➤  ${BOLD}rm -f $(NAME)${END}"

re: fclean all
