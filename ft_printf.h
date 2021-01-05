/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:00:12 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/05 12:57:26 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libftprintf/libftprintf.h"
# include <stdarg.h>

#include <stdio.h>


typedef struct	s_opt
{
	char	name;
	int		pad_left;
	int		hexa;
	int		nb_zero;
}				t_opt;

int				display(t_opt a, va_list *list);
void			init_opt(t_opt *a);
int				seach_param(char c);




#endif