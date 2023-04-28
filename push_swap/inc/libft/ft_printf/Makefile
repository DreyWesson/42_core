# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 10:32:16 by doduwole          #+#    #+#              #
#    Updated: 2023/02/02 11:55:26 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

SRCS			=	conversions/char.c conversions/str.c conversions/xes.c	\
					conversions/int.c libft/ft_putchar.c libft/ft_itoa.c	\
					libft/ft_strlen.c libft/ft_bzero.c libft/ft_calloc.c	\
					libft/ft_putstr.c conversions/ptr.c libft/ft_strchr.c	\
					libft/ft_strrev.c libft/ft_nbrlen.c libft/ft_dtox.c		\
					utils/ft_converter.c utils/str_validator.c ft_printf.c	\
					conversions/u.c libft/ft_utoa.c libft/ft_nbrlen_uns.c	\
					libft/ft_nbrlen_lng.c

OBJS			=	${SRCS:.c=.o}

CUSTOMOUTPUT	=	*.out

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

all:			${NAME}

${NAME}:		${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:
				${RM} ${OBJS} ${CUSTOMOUTPUT}

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re