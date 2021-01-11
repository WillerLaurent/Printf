/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:00:12 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/11 15:32:59 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libftprintf/libftprintf.h"
# include <stdarg.h>

#include <stdio.h>

# define BASE16L "0123456789abcdef"
# define BASE16U "0123456789ABCDEF"


typedef struct	s_opt
{
	char	type;
	char	indicator;
	int		width;
	int		sign_neg;
	int		sign_pos;
	int		precision;
	int		prec_exist;
	char	*data;
}				t_opt;

int				display(char *str, t_opt a);
void			init_opt(t_opt *a);
int				search_convert(char c);
int				search_indicator(char c);
t_opt			check_opt(const char *input, int i, t_opt a, va_list *list);
char 			*make_string(t_opt a, char *str);
char			*ft_substr(char *str, int start, int len);






#endif