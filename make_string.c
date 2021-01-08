/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 07:02:56 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/08 16:00:43 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *add_pad_right(char *str, int size)
{
	int len_str;

	len_str = ft_strlen(str);
	if (size > len_str)
		size = size - len_str;
	else if (size < len_str)
		size = len_str;
	while (size > 0)
	{
		str = ft_strjoin_right(str, ' ');
		size--;
	}
	return (str);
}

char *add_zero_left(char *str, int size)
{
	int len_str;

	len_str = ft_strlen(str);
	if (size > len_str)
		size = size - len_str;
	else if (size < len_str)
		size = len_str;
	while (size > 0)
	{
		str = ft_strjoin_left('0', str);
		size--;
	}
	return (str);
}

char *add_pad_left(char *str, int size)
{
	int len_str;

	len_str = ft_strlen(str);
	if (size > len_str)
		size = size - len_str;
	else if (size < len_str)
		size = len_str;
	while (size > 0)
	{
		str = ft_strjoin_left(' ', str);
		size--;
	}
	return (str);
}

char *mk_string_d(t_opt a, char *str)
{
	str = ft_strdup(a.data);
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
		else if (a.precision >= 0 || a.indicator != '0')
			str = add_pad_left(str, a.width);
		else if (a.precision < 0 && a.indicator == '0')
			str = add_zero_left(str, a.width);
	}
	return (str);
}

char *mk_string_s(t_opt a, char *str)
{
	if (a.precision > 0 && a.precision < ft_strlen(a.data))
		str = ft_substr(a.data, 0, a.precision);
	else
		str = ft_strdup(a.data);
	if (a.width > ft_strlen(str) && a.indicator == '-')
		str = add_pad_right(str, a.width);
	else if (a.width > ft_strlen(str))
		str = add_pad_left(str, a.width);
	return (str);
}

char *mk_string_prc(t_opt a, char *str)
{
	if (a.width > 1)
		str = add_pad_left(a.data, a.width);
	else
		str = ft_strdup(a.data);
	return (str);
}

char *make_string(t_opt a, char *str)
{
	if (a.type == 'd' || a.type == 'i' || a.type == 'u' || a.type == 'x' || a.type == 'X')
		str = mk_string_d(a, str);
	if (a.type == 's')
		str = mk_string_s(a, str);
	if (a.type == 'c')
		str = ft_strdup(a.data);
	if (a.type == '%')
		str = mk_string_prc(a, str);
	return (str);
}