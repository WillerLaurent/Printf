# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 07:31:33 by lwiller           #+#    #+#              #
#    Updated: 2021/01/05 13:12:56 by lwiller          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= Libftprintf/ft_atoi.c Libftprintf/ft_bzero.c Libftprintf/ft_calloc.c \
Libftprintf/ft_isdigit.c Libftprintf/ft_itoa.c Libftprintf/ft_strjoin.c \
Libftprintf/ft_strdup.c Libftprintf/ft_putchar_int.c \
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