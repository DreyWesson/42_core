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

PATH = ft_printf/conversions
PATH_TWO = ft_printf/utils

SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_strdup.c\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_strlen.c\
		ft_memcmp.c	ft_memcpy.c	ft_memmove.c ft_memset.c ft_putchar_fd.c $(PATH)/u.c\
		ft_putendl_fd.c	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
		ft_strncmp.c ft_striteri.c ft_strjoin.c	ft_strlcat.c ft_strlcpy.c ft_putstrnbr_fd.c\
		ft_strmapi.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_putstr.c	\
		ft_tolower.c ft_toupper.c ft_utoa.c ft_strrev.c ft_nbrlen.c ft_nbrlen_uns.c \
		ft_nbrlen_lng.c ft_dtox.c ft_bin_to_char.c ft_char_to_bin.c ft_putchar.c \
		ft_printf/ft_printf.c $(PATH)/char.c $(PATH)/str.c $(PATH)/xes.c $(PATH)/ptr.c \
		$(PATH)/int.c $(PATH_TWO)/ft_converter.c $(PATH_TWO)/str_validator.c

OBJS = $(SRCS:.c=.o)

BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS	= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus