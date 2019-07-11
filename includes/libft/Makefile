# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/03 13:06:49 by jmarin-h          #+#    #+#              #
#    Updated: 2019/06/18 16:34:48 by jmarin-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = ft_memchr.c\
ft_peer.c\
ft_bool.c\
ft_strcat.c\
ft_strncat.c\
ft_memcmp.c\
ft_strchr.c\
ft_strncmp.c\
ft_atoi.c\
ft_memcpy.c\
ft_strclr.c\
ft_strncpy.c\
ft_bzero.c\
ft_memdel.c\
ft_strcmp.c\
ft_strnequ.c\
ft_memmove.c\
ft_strcpy.c\
ft_strnew.c\
ft_isalnum.c\
ft_memset.c\
ft_strdel.c\
ft_strnstr.c\
ft_isalpha.c\
ft_strdup.c\
ft_strrchr.c\
ft_isascii.c\
ft_putchar.c\
ft_strequ.c\
ft_strsplit.c\
ft_isblank.c\
ft_putchar_fd.c\
ft_striter.c\
ft_strstr.c\
ft_isdigit.c\
ft_putendl.c\
ft_striteri.c\
ft_strsub.c\
ft_isprint.c\
ft_putendl_fd.c\
ft_strjoin.c\
ft_strtrim.c\
ft_itoa.c\
ft_putnbr.c\
ft_strlcat.c\
ft_tolower.c\
ft_lenword.c\
ft_putnbr_fd.c\
ft_strlen.c\
ft_strnlen.c\
ft_toupper.c\
ft_memalloc.c\
ft_putstr.c\
ft_strmap.c\
ft_countword.c\
ft_memccpy.c\
ft_putstr_fd.c\
ft_strmapi.c\
ft_lstnew.c\
ft_lstdelone.c\
ft_lstdel.c\
ft_lstadd.c\
ft_lstiter.c\
ft_lstmap.c\
ft_intlen.c\
get_next_line.c

CFLAGS = -Wall -Werror -Wextra
OBJS = $(SRC:.c=.o)
HEADER = libft.h

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Compilation :	\033[1;32mDONE!\033[m"


clean:
	@rm -f $(OBJS)
	@echo "Clean *.o :	\033[1;32mDONE!\033[m"


fclean: clean
	@rm -f $(NAME)
	@echo "Clean libft.a:	\033[1;32mDONE!\033[m"


re: fclean all

.PHONY: all clean fclean re
