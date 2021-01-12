/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 07:02:56 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/12 15:51:50 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char static	*mk_string_s(t_opt a, char *str)
{
	if (a.precision < 0)
		a.precision = ft_strlen(a.data);
	if (a.precision > 0 && a.precision < ft_strlen(a.data))
		str = ft_substr(a.data, 0, a.precision);
	else if (a.precision > 0 && a.precision >= ft_strlen(a.data))
		str = ft_strdup(a.data);
	else if (a.precision == 0 && a.prec_exist == 1)
		str = ft_strdup("");
	else if (a.prec_exist == 0)
		str = ft_strdup(a.data);
	if (a.width > ft_strlen(str) && a.indicator == '-')
		str = add_pad_right(str, a.width);
	else if (a.width > ft_strlen(str))
		str = add_pad_left(str, a.width);
	return (str);
}

char static	*mk_string_c(t_opt a, char *str)
{
	if (a.data == 0)
		str = ft_strdup("");
	else
		str = ft_strdup(a.data);
	if (a.width > 0)
		str = add_pad_left(str, a.width - 1);
	return (str);
}

char static	*mk_string_prc(t_opt a, char *str)
{
	if (a.width > 1)
		str = add_pad_left(a.data, a.width);
	else
		str = ft_strdup(a.data);
	return (str);
}

char static	*mk_string_p(t_opt a, char *str)
{
	str = ft_strdup("0x");
	if (a.data[0] == '0' && a.data[1] == '\0' && a.prec_exist == 1)
		return (str);
	str = ft_strjoin(str, a.data);
	if (a.width > ft_strlen(str))
	{
		if (a.indicator == '-')
			str = add_pad_right(str, a.width);
		else
			str = add_pad_left(str, a.width);
	}
	return (str);
}

char		*make_string(t_opt a, char *str)
{
	if (a.type == 'd' || a.type == 'i' || a.type == 'u' || a.type == 'x'
	|| a.type == 'X')
		str = mk_string_d(a, str);
	if (a.type == 's')
		str = mk_string_s(a, str);
	if (a.type == 'c')
		str = mk_string_c(a, str);
	if (a.type == '%')
		str = mk_string_prc(a, str);
	if (a.type == 'p')
		str = mk_string_p(a, str);
	return (str);
}