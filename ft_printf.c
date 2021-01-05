/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:09:45 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/05 15:15:03 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_opt static check_opt(const char *input, int i, t_opt a)
{
	int j;
	char *nbr;

	j = i;
	nbr = calloc(1, sizeof(char));
	if (input[i] == '0')
	{
		if (input[i + 1] == 'x')
			a.hexa = 1;
		if (input[i + 1] == 'X')
			a.hexa = 2;
		i++;
	}
	while (ft_isdigit(input[i]))
	{
		nbr = ft_strjoin_right(nbr, input[i]);
		i++;
	}
	if (input[i] == 'd' || input[i] == 'i')
		a.name = 'd';
	if (input[j] != '0')
		a.pad_left = ft_atoi(nbr);
	else
		a.nb_zero = ft_atoi(nbr);

	//printf("nb = %s, a.pad_left = %d, a.nb_zero = %d\n", nbr, a.pad_left, a.nb_zero);
	free(nbr);
	return (a);
}

int static check_input(const char *input, va_list *list, int i)
{
	//char *str;
	//int result;
	int count;
	t_opt a;

	count = 0;
	init_opt(&a);
	if (ft_isdigit(input[i]))
		a = check_opt(input, i, a);
	count = display(a, list);
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
			count_var = check_input(input, list, i + 1);
			count_char += count_var;
			while (seach_param(input[i]) == 0)
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
	int rtn;
	int rtn2;
	int rtn3;
//	int rtn4;

	char a;
	char str[] = "ZXCVC";
	int nb;

	a = 't';
	nb = 123;

	rtn = ft_printf("bonjour! |%010d| c'est %s moi %c qui teste\n", nb, nb, str, a);
	//rtn4 = ft_printf("bonjour! |%10d| c'est %s moi %c qui teste\n", nb, str, a);

	rtn2 = printf("bonjour! |%010d|c'est %s moi %c qui teste\n", nb, str, a);
	rtn3 = printf("bonjour! |%10d| c'est %s moi %c qui teste\n", nb, str, a);

	printf("\nrtn = %d\nrtn2 = %d\nrtn3 = %d\n", rtn, rtn2, rtn3);

	int ret;
	int i;

	i = -1;

	/*ret = ft_printf("Moi : |%16.2x|", -24);
	ft_printf("MoiR : ret = |%d|\n", ret);*/
	ret = printf("Lui : |%16x|", -24);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	/*ret = ft_printf("Moi : |%16.4X|", -24);
	ft_printf("MoiR : ret = |%d|\n", ret);*/
	ret = printf("Lui : |%16.4X|", -24);
	printf("LuiR : ret = |%d|\n", ret);
	i++;printf("i = %d\n\n-------------------\n\n", i);

}