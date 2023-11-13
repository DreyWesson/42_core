# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 13:21:00 by doduwole          #+#    #+#              #
#    Updated: 2023/11/12 09:04:42 by oduwoledare      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	main.c \
		src/graphics/index.c \
		src/graphics/input.c \
		src/parse/debugger.c \
		src/parse/index.c \
		src/graphics/init/game_init.c \
		src/graphics/init/texture_init.c \
		src/graphics/init/compass_init.c \
		src/graphics/render_image/frames.c \
		src/graphics/render_image/helper.c \
		src/graphics/render_image/helper_two.c \
		src/graphics/render_image/index.c \
		src/graphics/render_image/raycasting.c \
		src/graphics/update/index.c \
		src/graphics/update/moves.c \
		src/graphics/update/rotate.c \
		src/parse/extractors/color.c \
		src/parse/extractors/index.c \
		src/parse/extractors/map.c \
		src/parse/extractors/texture.c \
		src/parse/free/index.c \
		src/parse/init/index.c \
		src/parse/map/filler.c \
		src/parse/map/map.c \
		src/parse/printer/one.c \
		src/parse/printer/two.c \
		src/parse/utils/one.c \
		src/parse/utils/three.c \
		src/parse/utils/two.c \
		src/parse/validation/validate_cub.c \
		src/parse/validation/validate_map.c \
		src/parse/validation/validate_texture.c \
		src/parse/validation/validate_walls.c\

RM = rm -rf

CFLAGS = -Werror -Wall -Wextra

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc

OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = gcc -g -fsanitize=address 

LIBFTDIR = ./inc/libft

LIBFTA = $(LIBFTDIR)/libft.a


# Detect the operating system
UNAME_S := $(shell uname -s)

# macOS
ifeq ($(UNAME_S),Darwin)
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a
LINK = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Linux
else
MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
LINK = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
endif
# endif marks the end of a conditional block in a Makefile

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
WARNING='\033[33m'
DANGER='\033[31m'

.DEFAULT_GOAL := all

all: $(NAME)

$(NAME): $(LIBFTA) $(MLX) $(SRC) $(OBJS)
	@$(CC) $(OBJS) $(LIBFTA) $(LINK) -o $@
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)/%.o: %.c $(LIBFTA)
	@echo $(CURSIVE) "     - Building $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(MLX):
	@echo $(CURSIVE)$(WARNING) "     - (Wait a sec...) Building $@" $(NONE)
	@make -C $(MLX_DIR) > /dev/null 2>&1 || true

$(LIBFTA):
	@echo $(CURSIVE)$(WARNING) "     - (Wait a sec...) Building $@" $(NONE)
	@make all -C $(LIBFTDIR) > /dev/null || true

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)
	@make -C $(LIBFTDIR) clean > /dev/null || true
	@make -C $(MLX_DIR) clean > /dev/null || true
	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

fclean: clean
	@rm -f $(NAME) > /dev/null || true
	@make -C $(LIBFTDIR) fclean > /dev/null || true
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re: fclean all

.PHONY: all clean fclean re
