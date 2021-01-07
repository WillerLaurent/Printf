/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:00:12 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/07 10:12:42 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libftprintf/libftprintf.h"
# include <stdarg.h>

#include <stdio.h>


typedef struct	s_opt
{
	char	type;
	char	indicator;
	int		width;
	int		nb_zero;
	int		precision;
	char	*data;
}				t_opt;

int				display(char *str);
void			init_opt(t_opt *a);
int				seach_convert(char c);
t_opt			check_opt(const char *input, int i, t_opt a, va_list *list);
char 			*make_string(t_opt a, char *str);





#endif