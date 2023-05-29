# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 17:03:35 by doduwole          #+#    #+#              #
#    Updated: 2023/05/06 10:43:17 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

BONUS = checker
BONUS_MAIN = src/checker/checker.c

SRC_MAIN = src/push_swap.c

SRCS =		src/utils/*.c \
			src/operations/*.c \
			src/nodes/*.c \
			src/chunks/*.c

LIBFTDIR = ./inc/libft/
LIBFT = ./inc/libft/libft.a

RM = rm -rf

all: ${NAME}

${NAME}: ${SRCS} ${SRC_MAIN} ${LIBFT}
	@${CC} ${CFLAGS} $? -o $@

${LIBFT}:
	@make all -C ${LIBFTDIR}
	@make clean -C ${LIBFTDIR}

bonus: ${BONUS}

${BONUS}: ${SRCS} ${LIBFT} ${BONUS_MAIN}
	@${CC} ${CFLAGS} $? -o $@

clean: 
	@${MAKE} -C ${LIBFTDIR} fclean

fclean: clean
	@${RM} ${NAME}
	@${RM} ${BONUS}

re: fclean all

.PHONY: all clean fclean re