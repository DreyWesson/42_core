# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 20:17:29 by doduwole          #+#    #+#              #
#    Updated: 2023/03/21 04:41:19 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = server client

SRCS = *.c

LIBFTDIR = ./libft/
LIBFT = ./libft/libft.a

RM = rm -rf

all: ${NAME}

bonus: ${NAME}

server: server.c ${LIBFT}
	@$(CC) $(CFLAGS) server.c ${LIBFT} -o server

client: client.c ${LIBFT}
	@$(CC) $(CFLAGS) client.c ${LIBFT} -o client

${LIBFT}:
	@make all -C ${LIBFTDIR}
	@make clean -C ${LIBFTDIR}

clean: 
	@${MAKE} -C ./libft fclean

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re