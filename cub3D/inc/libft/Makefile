# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2022/12/29 15:58:46 by doduwole          #+#    #+#              #
# #    Updated: 2023/01/15 19:57:20 by doduwole         ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

NAME = libft.a

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
WARNING='\033[33m'
DANGER='\033[31m'


PRINTFDIR = ft_printf
CONVERSIONSDIR = ${PRINTFDIR}/conversions
UTILSDIR = ${PRINTFDIR}/utils
GETNEXTLNDIR = get_next_ln

SRCS =		ft_atoi.c \
			ft_bin_to_char.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_char_to_bin.c \
			ft_dtox.c \
			ft_free2d.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_nbrlen.c \
			ft_nbrlen_lng.c \
			ft_nbrlen_uns.c \
			ft_perror.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putstrnbr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_trim_front.c \
			ft_utoa.c \
			ft_printf/ft_printf.c \
			ft_printf/conversions/char.c \
			ft_printf/conversions/int.c \
			ft_printf/conversions/ptr.c \
			ft_printf/conversions/str.c \
			ft_printf/conversions/u.c \
			ft_printf/conversions/xes.c \
			ft_printf/utils/ft_converter.c \
			ft_printf/utils/str_validator.c \
			get_next_ln/get_next_line.c \
			get_next_ln/get_next_line_bonus.c

BONUS =		ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c\
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJ_DIR = obj

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

BONUS_OBJS	= $(BONUS:.c=$(OBJ_DIR)/%.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -I. -g -fsanitize=address 

all:			$(NAME)

$(NAME):		$(OBJS) 
	@ar rcs $(NAME) $(OBJS)> /dev/null 2>&1 || true
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)/%.o: %.c
	@echo $(CURSIVE) "     - Building $<" $(NONE)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS) $(OBJ_DIR) > /dev/null 2>&1 || true
	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

fclean:			clean
	@$(RM) $(NAME) > /dev/null 2>&1 || true
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re:				fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) > /dev/null 2>&1 || true

.PHONY:			all clean fclean re bonus 