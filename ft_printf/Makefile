# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igncipri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:40:17 by gcavanna          #+#    #+#              #
#    Updated: 2023/01/14 18:01:58 by igncipri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_calloc.c \
			ft_free.c \
			ft_itoa.c \
			ft_memset.c \
			ft_printf.c \
			ft_printf_elaboration.c \
			ft_printf_write.c \
			ft_ptrtoa.c \
			ft_utoa_base.c \
			ft_strlen.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libftprintf.a
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) -r libftprintf.a $(OBJ)

%.o: %.c
			$(CC) -c $(CFLAGS) $?

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

