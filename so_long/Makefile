# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 16:39:49 by doduwole          #+#    #+#              #
#    Updated: 2023/08/12 16:21:08 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

# SRC =	$(wildcard main.c inc/maps/*.c utils/*.c maps/*.c)
SRC =	$(wildcard main.c src/*.c src/*/*.c src/*/*/*.c src/*/*/*/*.c)


CFLAGS = -Werror -Wall -Wextra

OBJS = $(SRC:.c=.o)

CC = gcc -g -fsanitize=address 

LIBFTDIR = ./inc/libft/

LIBFTA = ./inc/libft/libft.a

MLX_DIR = ./mlx/

MLX = ./mlx/libmlx.a

LINK = -Lmlx -lmlx -framework OpenGL -framework AppKit

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

%.o: %.c $(LIBFTA)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@


$(NAME): $(LIBFTA) $(MLX) $(SRC) $(OBJS)
	@$(CC) $(OBJS) $(LIBFTA) $(LINK) -o $@
	@$(RM) $(OBJS)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(MLX):
	@make -C $(MLX_DIR)
	@make clean -C $(MLX_DIR)

$(LIBFTA):
	@make all -C $(LIBFTDIR)
	@make clean -C $(LIBFTDIR)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@$(MAKE) -C $(LIBFTDIR) fclean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# NAME = so_long

# SRC =	$(wildcard main.c utils/*.c maps/*.c)

# CFLAGS = -Werror -Wall -Wextra

# OBJS = $(SRC:.c=.o)

# CC = gcc -g -fsanitize=address 

# LIBFTDIR = ./inc/libft/

# LIBFTA = ./inc/libft/libft.a

# MLX_DIR = ./mlx/

# MLX = ./mlx/libmlx.a

# LINK = -Lmlx -lmlx -framework OpenGL -framework AppKit

# all: $(NAME)

# %.o: %.c $(LIBFTA)
# 		$(CC) $(CFLAGS) -Imlx -c $< -o $@

# $(NAME): $(LIBFTA) $(MLX) $(SRC) $(OBJS)
# 		$(CC) $(OBJS) $(LIBFTA) $(LINK) -o $(NAME)
# 		@make clean -C ./

# $(MLX):
# 	make -C $(MLX_DIR)

# $(LIBFTA):
# 	make -C $(LIBFTDIR)

# clean:
# 	$(RM) $(OBJS)
# 	make clean -C $(LIBFTDIR)

# fclean: clean
# 	make fclean -C $(LIBFTDIR)
# 	$(RM) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re
