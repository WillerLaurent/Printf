/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:09:45 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/14 11:45:39 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_input(const char *input, va_list *list, int i)
{
	int		count;
	t_opt	a;
	char	*str;

	count = 0;
	str = NULL;
	init_opt(&a);
	a = check_opt(input, i, a, list);
	str = make_string(a, str);
	count = display(str, a);
	if (a.malloc_data == 1)
		free(a.data);
	free(str);
	return (count);
}

int	read_string(const char *input, va_list *list)
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
			while (search_convert(input[i]) == 0)
				i++;
		}
		i++;
	}
	return (count_char);
}

int	ft_printf(const char *input, ...)
{
	va_list	list;
	int		result;

	va_start(list, input);
	result = read_string(input, &list);
	va_end(list);
	return (result);
}
