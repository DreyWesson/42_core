# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 17:03:35 by doduwole          #+#    #+#              #
#    Updated: 2023/03/21 12:50:23 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRCS = *.c utils/*.c

LIBFTDIR = ./libft/
LIBFT = ./libft/libft.a

RM = rm -rf

all: ${NAME}

${NAME}: ${SRCS} ${LIBFT}
	@${CC} ${CFLAGS} ${SRCS} ${LIBFT} -o ${NAME}

${LIBFT}:
	@make all -C ${LIBFTDIR}
	@make clean -C ${LIBFTDIR}

clean: 
	@${MAKE} -C ./libft fclean

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re