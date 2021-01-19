/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 07:02:56 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/19 11:10:04 by lwiller          ###   ########lyon.fr   */
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
	if (a.c_zero == 1)
	{
		free(str);
		str = ft_strdup("");
	}
	else
		str = ft_strdup(a.data);
	if (ft_strlen(str) == 0)
	{
		if (a.width > 0)
			a.width--;
	}
	if (a.width > 0)
	{
		if (a.indicator == '-')
			str = add_pad_right(str, a.width);
		else
			str = add_pad_left(str, a.width);
	}
	return (str);
}

char static	*mk_string_prc(t_opt a, char *str)
{
	str = ft_strdup(a.data);
	if (a.width > 1 && a.indicator != '-')
		str = add_pad_left(str, a.width);
	if (a.width > 1 && a.indicator == '-')
		str = add_pad_right(str, a.width);
	return (str);
}

char static	*mk_string_p(t_opt a, char *str)
{
	if (a.data[0] == '0' && a.data[1] == '\0' && a.prec_exist == 1)
		str = ft_strdup("0x");
	else
	{
		str = ft_strdup("0x");
		str = ft_strjoin(str, a.data);
	}
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
	else if (a.type == 's')
		str = mk_string_s(a, str);
	else if (a.type == 'c')
		str = mk_string_c(a, str);
	else if (a.type == '%')
		str = mk_string_prc(a, str);
	else if (a.type == 'p')
		str = mk_string_p(a, str);
	return (str);
}
