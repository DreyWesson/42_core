# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 16:39:49 by doduwole          #+#    #+#              #
#    Updated: 2023/05/04 21:07:43 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

CC = gcc -g -fsanitize=address

LIBFTDIR = ./inc/libft/

LIBFT = ./inc/libft/libft.a

MLXDIR = ./mlx

MLX = ./mlx/libmlx.a

RM = rm -rf

all: ${NAME}

%.o: %.c	${LIBFT}
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):	$(LIBFT) $(MLX) ${SRC} $(OBJS)
			$(CC) $? -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

${MLX}:
	@make -C ${MLXDIR}

${LIBFT}:
	@make all -C ${LIBFTDIR}
	@make clean -C ${LIBFTDIR}

clean: 
	@${MAKE} -C ./libft fclean

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re