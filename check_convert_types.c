/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_convert_types.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 08:06:34 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/19 08:39:38 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_opt	check_convert_digit(t_opt a, va_list *list)
{
	long int n;

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

t_opt	check_convert_pointer(t_opt a, va_list *list)
{
	unsigned long n;

	n = va_arg(*list, unsigned long);
	a.data = ft_iota_base(n, BASE16L);
	a.malloc_data = 1;
	return (a);
}

t_opt	check_convert_hexa(t_opt a, va_list *list)
{
	unsigned int n;

	n = va_arg(*list, unsigned int);
	if (a.type == 'x')
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

t_opt	check_convert_c(t_opt a, va_list *list)
{
	char c;

	c = va_arg(*list, int);
	if (c == 0)
		a.c_zero = 1;
	a.data = ft_calloc(2, sizeof(char));
	a.data[0] = c;
	a.malloc_data = 1;
	return (a);
}
