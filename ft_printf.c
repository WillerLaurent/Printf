/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:09:45 by lwiller           #+#    #+#             */
/*   Updated: 2020/12/23 13:24:16 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int read_string(const char *input, va_list *list)
{
	int count_char;
	int i;
	char *str;
	int result;

	count_char = 0;
	str = NULL;
	result = 0;
	i = 0;

	while (input[i])
	{
		if (input[i] != '%')
			count_char += ft_putchar_int(input[i]);
		if (input[i] == '%')
		{
			i++;
			if (input[i] == 'c')
				count_char += ft_putchar_int(va_arg(*list, int));
			if (input[i] == 'd')
			{
				result = va_arg(*list, int);
				str = ft_itoa(result);
				count_char += ft_putstr_int(str);
			}
			if (input[i] == 's')
			{
				str = va_arg(*list, char*);
				count_char += ft_putstr_int(str);
			}
		}
		i++;
	}
	return (count_char);
}

int ft_printf(const char *input, ...)
{
	va_list list;
	int result;

	va_start(list, input);
	result = read_string(input, &list);
	va_end(list);
	return (result);
}

#include <stdio.h>

int main()
{
	int rtn;
	char a;
	char str[] = "ZXCVC";
	int nb;

	a = 't';
	nb = 123;

	rtn = ft_printf("bonjour! %d c'est %s moi %c qui teste", nb, str, a);

	printf("\nrtn = %d\n", rtn);
}