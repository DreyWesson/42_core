# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 19:34:40 by doduwole          #+#    #+#              #
#    Updated: 2023/09/05 20:28:58 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

SRC =	$(wildcard *.c src/*.c src/*/*.c src/*/*/*.c src/*/*/*/*.c)

RM = rm -rf

CFLAGS = -Werror -Wall -Wextra

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc

OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = gcc -g -pthread -fsanitize=address 

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
WARNING='\033[33m'

all: $(NAME)

$(NAME): $(SRC) $(OBJS)
	@$(CC) $(OBJS) -o $@
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)/%.o: %.c
	@echo $(CURSIVE)$(GRAY) "     - Building $<" $(NONE)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

fclean: clean
	@rm -f $(NAME)
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re: fclean all

.PHONY: all clean fclean re
