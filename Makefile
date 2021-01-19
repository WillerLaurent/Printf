# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 07:31:33 by lwiller           #+#    #+#              #
#    Updated: 2021/01/19 09:27:56 by lwiller          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= Libftprintf/ft_atoi.c Libftprintf/ft_bzero.c Libftprintf/ft_calloc.c \
Libftprintf/ft_isdigit.c Libftprintf/ft_itoa_base.c Libftprintf/ft_itoa.c \
Libftprintf/ft_strdup.c Libftprintf/ft_putchar_int.c \
Libftprintf/ft_strjoin.c Libftprintf/ft_putstr_int.c Libftprintf/ft_substr.c \
Libftprintf/ft_strlen.c \
add_pad_and_zero.c check_convert.c check_convert_types.c check_opt.c display.c \
ft_printf.c init_opt.c make_string_d.c make_string.c search_convert.c 

INCS	= Libftprintf/libftprintf.h ft_printf.h 

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

norme:	
		norminette -R CheckForbiddenSourceHeader *.c */*.c
		norminette -R CheckDefine *.h */*.h

.PHONY: fclean clean re all