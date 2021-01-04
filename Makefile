# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 07:31:33 by lwiller           #+#    #+#              #
#    Updated: 2021/01/04 10:41:48 by lwiller          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= Libftprintf/ft_itoa.c Libftprintf/ft_putchar_int.c \
Libftprintf/ft_putstr_int.c Libftprintf/ft_strlen.c \

INCS	= Libftprintf/libftprintf.h

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

%.o: %.c	libft.h
		$(CC) -c $< $(CFLAGS)

${NAME}:${OBJS}
		 ar rcs ${NAME} ${OBJS}
		
all:	${NAME}

clean:	
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY: fclean clean re all