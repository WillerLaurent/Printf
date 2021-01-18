/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:00:12 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/18 09:40:25 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libftprintf/libftprintf.h"
# include <stdarg.h>

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
	int		c_zero;
	char	*data;
	int		malloc_data;
}				t_opt;

int				display(char *str, t_opt a);
void			init_opt(t_opt *a);
int				search_convert(char c);
int				search_indicator(char c);
t_opt			check_opt(const char *input, int i, t_opt a, va_list *list);
t_opt			check_convert(t_opt a, va_list *list);
char			*make_string(t_opt a, char *str);
char			*mk_string_d(t_opt a, char *str);
char			*ft_substr(char *str, int start, int len);
char			*add_pad_right(char *str, int size);
char			*add_zero_left(char *str, int size);
char			*add_pad_left(char *str, int size);
int				ft_printf(const char *input, ...);

#endif
