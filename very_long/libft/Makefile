CC = gcc
 
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

OBJ =  ft_strdup.o				ft_atoi.o \
			ft_bzero.o              ft_strjoin.o \
			ft_calloc.o              ft_strlcat.o \
			ft_isalnum.o            ft_memchr.o             ft_strlcpy.o \
			ft_isalpha.o            ft_memcmp.o             ft_strlen.o \
			ft_isascii.o            ft_memcpy.o             ft_strmapi.o \
			ft_isdigit.o            ft_memmove.o             ft_strncmp.o \
			ft_isprint.o            ft_memset.o             ft_strnstr.o \
			ft_itoa.o               ft_putchar_fd.o         ft_strrchr.o \
			ft_numcountforp.o       ft_print_p.o            ft_put_ptr.o \
		    ft_putendl_fd.o         ft_strtim.o            ft_printf.o \
			get_next_line.o \
		    ft_putnbr_fd.o          ft_substr.o            ft_put.o \
		    ft_putstr_fd.o          ft_tolower.o           ft_puthexi.o \
		    ft_split.o              ft_toupper.o         ft_utoa.o \
		    ft_strchr.o				ft_striteri.o \
  
B_SRC = ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c \
					ft_lstdelone.c		ft_lstiter.c			ft_lstlast.c \
					ft_lstsize.c			ft_lstmap.c			ft_lstnew.c \

B_OBJ = $(B_SRC:.c=.o)
			
all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ) : %.o : %.c

bonus : $(OBJ) $(B_OBJ)
			ar rcs $(NAME) $(OBJ) $(B_OBJ)

clean:
	@echo "Cleaning Israel's Files........."
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean  $(NAME) 
	