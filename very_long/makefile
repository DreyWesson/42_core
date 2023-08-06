# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 11:49:55 by ioduwole          #+#    #+#              #
#    Updated: 2023/02/13 15:24:35 by ioduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c checks.c map_validate.c checks2.c \
	game_graphics.c game_moves.c moves2.c

CFLAGS = -Werror -Wall -Wextra

OBJS = $(SRC:.c=.o)

CC = gcc -g -fsanitize=address 

LIBFTDIR = ./libft/

LIBFTA = ./libft/libft.a

MLX_DIR = ./mlx/

MLX = ./mlx/libmlx.a

all: $(NAME)

%.o: %.c $(LIBFTA)
		$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(LIBFTA) $(MLX) $(SRC) $(OBJS)
		$(CC) $(OBJS) $(LIBFTA) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

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