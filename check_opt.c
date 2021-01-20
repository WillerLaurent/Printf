/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:05:43 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/20 07:16:54 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_opt	check_indicator(const char *input, t_opt a, int i)
{
	int zero;
	int sign_neg;
	int sign_pos;

	zero = 0;
	sign_neg = 0;
	sign_pos = 0;
	while (search_indicator(input[i]))
	{
		if (input[i] == '0')
			zero = 1;
		if (input[i] == '-')
			sign_neg = 1;
		if (input[i] == '+')
			sign_pos = 1;
		i++;
	}
	if (sign_pos == 1)
		a.sign_pos = 1;
	if (sign_neg == 0 && zero == 1)
		a.indicator = '0';
	else if (sign_neg == 1)
		a.indicator = '-';
	return (a);
}

t_opt	check_width(const char *input, t_opt a, int i, va_list *list)
{
	char *nbr;

	nbr = ft_calloc(1, sizeof(char));
	if (ft_isdigit(input[i]))
	{
		while (ft_isdigit(input[i]))
		{
			nbr = ft_strjoin_right(nbr, input[i]);
			i++;
		}
		a.width = ft_atoi(nbr);
	}
	else if (input[i] == '*')
	{
		a.width = va_arg(*list, int);
		if (a.width < 0)
		{
			a.indicator = '-';
			a.width = a.width * (-1);
		}
		i++;
	}
	free(nbr);
	return (a);
}

t_opt	check_precision(const char *input, t_opt a, int i, va_list *list)
{
	char *nbr;

	a.prec_exist = 1;
	if (input[i] == '-')
		return (a);
	nbr = ft_calloc(1, sizeof(char));
	if (ft_isdigit(input[i]))
	{
		while (ft_isdigit(input[i]))
		{
			nbr = ft_strjoin_right(nbr, input[i]);
			i++;
		}
		a.precision = ft_atoi(nbr);
	}
	else if (input[i] == '*')
		a.precision = va_arg(*list, int);
	else if (!(ft_isdigit(input[i])))
		a.precision = 0;
	free(nbr);
	return (a);
}

t_opt	find_type(char c, va_list *list, t_opt a)
{
	if (search_convert(c))
	{
		a.type = c;
		a = check_convert(a, list);
	}
	else
	{
		a.type = 'o';
		a.data = ft_calloc(2, sizeof(char));
		a.data[0] = c;
		a.malloc_data = 1;
	}
	return (a);
}

t_opt	check_opt(const char *input, int i, t_opt a, va_list *list)
{
	if (search_indicator(input[i]))
	{
		a = check_indicator(input, a, i);
		while (search_indicator(input[i]))
			i++;
	}
	if (ft_isdigit(input[i]) || input[i] == '*')
	{
		a = check_width(input, a, i, list);
		while (ft_isdigit(input[i]) || input[i] == '*')
			i++;
	}
	if (input[i] == '.')
	{
		i++;
		a = check_precision(input, a, i, list);
		while (ft_isdigit(input[i]) || input[i] == '-' || input[i] == '*')
			i++;
	}
	a = find_type(input[i], list, a);
	return (a);
}
