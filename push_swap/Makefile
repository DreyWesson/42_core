# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 17:03:35 by doduwole          #+#    #+#              #
#    Updated: 2023/04/28 07:09:54 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

BONUS = checker
BONUS_MAIN = ./checker/checker.c

SRCS =		src/*.c \
			src/utils/*.c \
			src/operations/*.c \
			src/nodes/*.c \
			src/chunks/*.c

LIBFTDIR = ./inc/libft/
LIBFT = ./inc/libft/libft.a

RM = rm -rf

all: ${NAME}

${NAME}: ${SRCS} ${LIBFT}
	@${CC} ${CFLAGS} ${SRCS} ${LIBFT} -o ${NAME}

${LIBFT}:
	@make all -C ${LIBFTDIR}
	@make clean -C ${LIBFTDIR}

bonus: ${BONUS}

${BONUS_MAIN}: ${SRCS} ${BONUS_MAIN} ${LIBFT}
	@${CC} ${CFLAGS} ${SRCS} ${BONUS_MAIN} ${LIBFT} -o ${BONUS}


clean: 
	@${MAKE} -C ./libft fclean

fclean: clean
	@${RM} ${NAME}
	@${RM} ${BONUS}

re: fclean all

.PHONY: all clean fclean re