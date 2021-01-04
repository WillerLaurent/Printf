/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:09:45 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/04 13:39:48 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int static check_input(const char *input, va_list *list, int i)
{
	char *str;
	int result;
	int count;

	count = 0;
	if (input[i] == 'c')
		count += ft_putchar_int(va_arg(*list, int));
	printf("//count1 = %d\n", count);
	if (input[i] == 'd')
	{
		result = va_arg(*list, int);
		str = ft_itoa(result);
		count += ft_putstr_int(str);
			printf("//count2 = %d\n", count);
	}
	if (input[i] == 's')
	{
		str = va_arg(*list, char *);
		count += ft_putstr_int(str);
			printf("//count3 = %d\n", count);
	}
	return (count);
}

int static read_string(const char *input, va_list *list)
{
	int count_char;
	int count_var;
	int i;
	/*char *str;
	int result;*/

	count_char = 0;
	count_var = 0;
	/*str = NULL;
	result = 0;*/
	i = 0;

	while (input[i])
	{
		if (input[i] != '%')
			count_char += ft_putchar_int(input[i]);
		if (input[i] == '%')
		{
			i++;
			count_var = check_input(input, list, i);
			/*if (input[i] == 'c')
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
			}*/
			count_char += count_var; 
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
	int rtn2;

	char a;
	char str[] = "ZXCVC";
	int nb;

	a = 't';
	nb = 123;

	rtn = ft_printf("bonjour! %d c'est %s moi %c qui teste\n", nb, str, a);
	rtn2 = printf("bonjour! %0xd c'est %s moi %c qui teste\n", nb, str, a);

	printf("\nrtn = %d\nrtn2 = %d\n", rtn, rtn2);
}