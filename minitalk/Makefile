# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 20:17:29 by doduwole          #+#    #+#              #
#    Updated: 2023/03/19 08:29:02 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.c libft.a
	@$(CC) $(CFLAGS) server.c libft/libft.a -o server

client: client.c libft.a
	@$(CC) $(CFLAGS) client.c libft/libft.a -o client

libft.a:
	make all -C ./libft

clean:
	make clean -C libft/
	
fclean: 
	@rm -f server
	@rm -f client
	@make fclean -C libft

re: fclean all