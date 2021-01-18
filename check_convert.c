/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:51:47 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/18 16:34:23 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_opt	check_convert_digit(t_opt a, va_list *list)
{
	long long n;

	if (a.type == 'u')
		n = va_arg(*list, unsigned int);
	else
		n = va_arg(*list, int);
	if (n < 0)
	{
		n = n * (-1);
		a.sign_neg = 1;
	}
	a.data = ft_itoa(n);
	a.malloc_data = 1;
	return (a);
}

t_opt	check_convert_hexa(t_opt a, va_list *list)
{
	unsigned int n;

	n = va_arg(*list, unsigned int);
	if (a.type == 'x' || a.type == 'p')
		a.data = ft_iota_base(n, BASE16L);
	else
		a.data = ft_iota_base(n, BASE16U);
	a.malloc_data = 1;
	return (a);
}

t_opt	check_convert_s(t_opt a, va_list *list)
{
	a.data = va_arg(*list, char *);
	if (a.data == NULL)
	{
		a.data = ft_strdup("(null)");
		a.malloc_data = 1;
	}
	return (a);
}

t_opt	check_convert(t_opt a, va_list *list)
{
	char c;

	if (a.type == 'd' || a.type == 'i' || a.type == 'u')
		a = check_convert_digit(a, list);
	if (a.type == 's')
		a = check_convert_s(a, list);
	if (a.type == 'c')
	{
		c = va_arg(*list, int);
		if (c == 0)
			a.c_zero = 1;
		a.data = ft_calloc(2, sizeof(char));
		a.data[0] = c;
		a.malloc_data = 1;
	}
	if (a.type == '%')
	{
		a.data = ft_calloc(2, sizeof(char));
		a.data[0] = '%';
		a.malloc_data = 1;
	}
	if (a.type == 'x' || a.type == 'X' || a.type == 'p')
		a = check_convert_hexa(a, list);
	return (a);
}
