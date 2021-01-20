/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:51:47 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/20 07:17:11 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_opt	check_convert(t_opt a, va_list *list)
{
	if (a.type == 'd' || a.type == 'i' || a.type == 'u')
		a = check_convert_digit(a, list);
	else if (a.type == 's')
		a = check_convert_s(a, list);
	else if (a.type == 'c')
		a = check_convert_c(a, list);
	else if (a.type == '%')
	{
		a.data = ft_calloc(2, sizeof(char));
		a.data[0] = '%';
		a.malloc_data = 1;
	}
	else if (a.type == 'x' || a.type == 'X')
		a = check_convert_hexa(a, list);
	else if (a.type == 'p')
		a = check_convert_pointer(a, list);
	return (a);
}
