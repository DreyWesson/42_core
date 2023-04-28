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

PRINTFDIR = ft_printf
CONVERSIONSDIR = ${PRINTFDIR}/conversions
UTILSDIR = ${PRINTFDIR}/utils
GETNEXTLNDIR = get_next_ln

SRCS = $(wildcard *.c ${PRINTFDIR}/*.c ${CONVERSIONSDIR}/*.c ${UTILSDIR}/*.c ${GETNEXTLNDIR}/*.c)

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
				@make clean -C ./

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus