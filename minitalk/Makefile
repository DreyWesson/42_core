# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 20:17:29 by doduwole          #+#    #+#              #
#    Updated: 2023/03/02 08:44:44 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME1 = client
# NAME2 = server



# SRCS =	./mandatory/client.c ./mandatory/server.c \


# LIBFTDIR = ./libft
# LIBFT = ./libft/libft.a

# FT_PRINTFDIR = ./ft_printf
# FT_PRINTF = ./ft_printf/libftprintf.a

# # BONUS =	bonus/client.c bonus/server.c

# # BONUS_OBJS	= $(BONUS:.c=.o)

# CC				= gcc
# RM				= rm -f
# CFLAGS			= -Wall -Wextra -Werror

# all:			$(NAME)

# $(NAME):		$(SRC) $(LIBFT) $(FT_PRINTF)
# 				$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(FT_PRINTF) -o $(NAME)

# $(LIBFT):
# 				cd $(LIBFTDIR) && make all && cd ../

# $(FT_PRINTF):
# 				cd $(FT_PRINTFDIR) && make all
	

# clean:
# 				$(RM) $(OBJS)
# # $(BONUS_OBJS)

# fclean:			clean
# 				$(RM) $(NAME)

# re:				fclean $(NAME)

# # bonus:			$(OBJS) $(BONUS_OBJS)
# # 				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# .PHONY:			all clean fclean re 
# # bonus
SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

# bonus: server client

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re