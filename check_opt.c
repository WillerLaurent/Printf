/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:05:43 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/11 16:31:14 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_opt static check_indicator(const char *input, t_opt a, int i)
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

t_opt static check_precision(const char *input, t_opt a, int i, va_list *list)
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
	{
		a.precision = va_arg(*list, int);
		if (a.precision < 0)
			a.precision = 0;
	}
	else if (!(ft_isdigit(input[i])))
		a.precision = 0;

	free(nbr);
	return (a);
}

t_opt check_opt(const char *input, int i, t_opt a, va_list *list)
{
	char *nbr;
	int long n;
	char c;

	nbr = calloc(1, sizeof(char));

	/*indicator rempli a.indicator*/
	if (search_indicator(input[i]))
	{
		a = check_indicator(input, a, i);
		while (search_indicator(input[i]))
			i++;
	}

	/*width rempli a.width*/
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

	/*precision rempli a.precision*/
	if (input[i] == '.')
	{
		i++;
		a = check_precision(input, a, i, list);
		while (ft_isdigit(input[i]) || input[i] == '-' || input[i] == '*')
			i++;
	}

	/*type rempli a.data*/
	if (search_convert(input[i]))
	{
		a.type = input[i];
		if (a.type == 'd' || a.type == 'i' || a.type == 'u')
		{
			if (a.type == 'u')
				n = va_arg(*list, unsigned int);
			else
				n = va_arg(*list, int);
			//metre valeur abs ds itoa, mettre champ sign_neg a 1
			if (n < 0)
			{
				n = n * (-1);
				a.sign_neg = 1;
			}
			a.data = ft_itoa(n);
		}
		if (a.type == 's')
		{
			a.data = va_arg(*list, char *);
			if (a.data == NULL)
				a.data = ft_strdup("(null)");
		}
		if (a.type == 'c')
		{
			c = va_arg(*list, int);
			a.data = ft_calloc(2, sizeof(char));
			a.data[0] = c;
		}
		if (a.type == '%')
		{
			a.data = ft_calloc(2, sizeof(char));
			a.data[0] = '%';
		}
		if (a.type == 'x' || a.type == 'X' || a.type == 'p')
		{
			if (a.type == 'p')
				n = va_arg(*list, unsigned int);
			else
				n = va_arg(*list, unsigned int);
			if (a.type == 'x' || a.type == 'p')
				a.data = ft_iota_base(n, BASE16L);
			else
				a.data = ft_iota_base(n, BASE16U);
		}
	}

	//printf("\na.width = %d\n", a.width);
	free(nbr);
	return (a);
}