/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:09:45 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/08 16:01:50 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static check_input(const char *input, va_list *list, int i)
{
	int count;
	t_opt a;
	char *str;

	count = 0;
	str = NULL;
	init_opt(&a);
	/*if (seach_convert(input[i]))
	{
				a.type = input[i];
				a.data = 

	}*/
	//	printf("a.type = %c\n", a.type);
	//if (!(seach_convert(input[i])))
	a = check_opt(input, i, a, list);
	str = make_string(a, str);
	

	count = display(str);
	if (ft_strlen(str) > 0)
		free(str);
	/*if (input[i] == 'c')
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
	}*/
	return (count);
}

int static read_string(const char *input, va_list *list)
{
	int count_char;
	int count_var;
	int i;

	count_char = 0;
	count_var = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] != '%')
			count_char += ft_putchar_int(input[i]);
		if (input[i] == '%')
		{
			i++;
			count_var = check_input(input, list, i);
			count_char += count_var;
			while (seach_convert(input[i]) == 0)
				i++;
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

int main()
{
	int ret;
	int i;

	i = -1;
	ret = ft_printf("Moi : |%16.2x|", -24);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%016.2x|", -24);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%16.4X|", -24);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%16.4X|", -24);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);


	ret = ft_printf("Moi : |%3%|");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%3%|");
	printf("LuiR : ret = |%d|\n", ret);
	i++;
	ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%16.2u|", -24);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%16.2u|", -24);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%16.2u|", 24);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%16.2u|", 24);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%16.2u|", 2468);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%16.2u|", 2468);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%16.2u|", 2);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%16.2u|", 2);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%-45.0u|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-45.0u|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%45.0u|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%45.0u|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%0.0u|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%0.0u|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);
//10

ret = ft_printf("Moi : |%0.0d|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%0.0d|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%0.0x|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%0.0x|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%-10.8X|%d|%5.4d|%x|%X|d|", -1, 123, 456, 7, 8);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-10.8X|%d|%5.4d|%x|%X|d|", -1, 123, 456, 7, 8);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%-10.8X|%-10.8d|%5.4d|%x|%X|d|", -1, 123, 456, 7, 8);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-10.8X|%-10.8d|%5.4d|%x|%X|d|", -1, 123, 456, 7, 8);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%-10.8X|", -1);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-10.8X|", -1);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%.x|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.x|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%-10.8X|", -12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-10.8X|", -12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%10d|", -12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%10d|", -12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%10.6d|", -12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%10.6d|", -12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%10.7d|", -12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%10.7d|", -12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);
}