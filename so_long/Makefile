# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 16:39:49 by doduwole          #+#    #+#              #
#    Updated: 2023/05/29 12:36:04 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =	$(wildcard main.c utils/*.c maps/*.c)

CFLAGS = -Werror -Wall -Wextra

OBJS = $(SRC:.c=.o)

CC = gcc -g -fsanitize=address 

LIBFTDIR = ./inc/libft/

LIBFTA = ./inc/libft/libft.a

MLX_DIR = ./mlx/

MLX = ./mlx/libmlx.a

LINK = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c $(LIBFTA)
		$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(LIBFTA) $(MLX) $(SRC) $(OBJS)
		$(CC) $(OBJS) $(LIBFTA) $(LINK) -o $(NAME)
		@make clean -C ./

$(MLX):
	make -C $(MLX_DIR)

$(LIBFTA):
	make -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFTDIR)

fclean: clean
	make fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
