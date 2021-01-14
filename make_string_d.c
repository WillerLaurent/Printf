/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:35:18 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/14 15:01:29 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mk_str_with_prec(t_opt a, char *str)
{
	if (a.precision < 0)
		a.precision = 1;
	if (a.precision == 0 && str[0] == '0' && ft_strlen(str) == 1)
	{
		free(str);
		str = ft_strdup("");
	}
	else if (a.precision > ft_strlen(str))
		str = add_zero_left(str, a.precision);
	if (a.sign_neg == 1)
		str = ft_strjoin_left('-', str);
	if (a.width > ft_strlen(str))
	{
		if (a.indicator == '-')
			str = add_pad_right(str, a.width);
		else
			str = add_pad_left(str, a.width);
	}
	return (str);
}

char	*mk_str_without_prec(t_opt a, char *str)
{
	if (a.width > ft_strlen(str))
	{
		if (a.indicator == '0')
		{
			if (a.sign_neg == 1 && a.width > ft_strlen(str) + 1)
				str = add_zero_left(str, a.width - 1);
			else if (a.sign_neg == 0)
				str = add_zero_left(str, a.width);
		}
		if (a.sign_neg == 1)
			str = ft_strjoin_left('-', str);
		if (a.width > ft_strlen(str))
		{
			if (a.indicator == 0)
				str = add_pad_left(str, a.width);
			if (a.indicator == '-')
				str = add_pad_right(str, a.width);
		}
	}
	return (str);
}

char	*mk_string_d(t_opt a, char *str)
{
	str = ft_strdup(a.data);
	if (a.prec_exist == 1)
	{
		str = mk_str_with_prec(a, str);
	}
	else if (a.prec_exist == 0 && a.width > ft_strlen(str))
	{
		str = mk_str_without_prec(a, str);
	}
	else if (a.prec_exist == 0 && a.width <= ft_strlen(str))
	{
		if (a.sign_neg == 1)
			str = ft_strjoin_left('-', str);
	}
	return (str);
}
