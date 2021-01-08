/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:05:43 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/08 10:46:37 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_opt static check_precision(const char *input, t_opt a, int i, va_list *list)
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
		a.precision = ft_atoi(nbr);
	}
	else if (input[i] == '*')
		a.precision = va_arg(*list, int);
	free(nbr);
	return (a);
}

t_opt check_opt(const char *input, int i, t_opt a, va_list *list)
{
	char *nbr;
	int long n;
	char c;

	nbr = calloc(1, sizeof(char));
	if (input[i] == '0' || input[i] == '-')
	{
		a.indicator = input[i];
		if (input[i + 1] == '0' || input[i + 1] == '-')
		{
			a.indicator = '-';
			i++;
		}
		i++;
	}
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
		i++;
	}
	if (input[i] == '.')
	{
		i++;
		a = check_precision(input, a, i, list);
		while (ft_isdigit(input[i]))
			i++;
	}
	if (seach_convert(input[i]))
	{
		a.type = input[i];
		if (a.type == 'd' || a.type == 'i' || a.type == 'u')
		{
			if (a.type == 'u')
				n = va_arg(*list, unsigned int);
			else
				n = va_arg(*list, int);
			a.data = ft_itoa(n);
		}
		if (a.type == 's')
			a.data = va_arg(*list, char *);
		if (a.type == 'c')
		{
			c = va_arg(*list, int);
			a.data = ft_calloc(2, sizeof(char));
			a.data[0] = c;
		}
	}

	//printf("\na.width = %d\n", a.width);
	free(nbr);
	return (a);
}