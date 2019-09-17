# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 10:32:28 by ralleman          #+#    #+#              #
#    Updated: 2019/09/16 12:43:38 by avogt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = allocate_board.c block_fit.c check_error.c check_blocks.c fill_struct.c\
get_blocks.c get_board_size.c get_one_line.c main.c print_board.c\
put_in_board.c resize_board.c resolve.c sharp_to_alpha.c free_board.c\
struct_len.c
CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJ = $(SRC:.c=.o)
LIB = ./libft/libft.a


all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@gcc $(CFLAGS) -L./libft/ -lft $(OBJ) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I ./libft/

clean:
	@make clean -C ./libft/
	@rm -f $(OBJ)

fclean: clean
	@make clean -C ./libft/
	@rm -f $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
