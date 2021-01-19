/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 07:01:20 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/19 08:18:49 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_c(char *str, t_opt a, int count)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	if (a.width > 1 && a.indicator != '-')
	{
		while (i < len)
		{
			count += ft_putchar_int(str[i]);
			i++;
		}
		count += ft_putchar_int(0);
	}
	else
	{
		count += ft_putchar_int(0);
		while (i < len)
		{
			count += ft_putchar_int(str[i]);
			i++;
		}
	}
	return (count);
}

int	display(char *str, t_opt a)
{
	int count;
	int i;
	int len;

	count = 0;
	i = 0;
	len = ft_strlen(str);
	if (a.c_zero == 1)
		count = display_c(str, a, count);
	else
		count = ft_putstr_int(str);
	return (count);
}
