/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 07:01:20 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/18 17:04:06 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display(char *str, t_opt a)
{
	int count;
	int i;
	int len;
	
	count = 0;
	i = 0;
	len = ft_strlen(str);
	if (a.c_zero == 1 && a.width > 1 && a.indicator != '-')
	{
		while (i < len)
		{
			count += ft_putchar_int(str[i]);
			i++;
		}
		count += ft_putchar_int(0);
	}
	else if (a.c_zero == 1)
	{
		count += ft_putchar_int(0);
		while (i < len)
		{
			count += ft_putchar_int(str[i]);
			i++;
		}
		
	}
	else
		count += ft_putstr_int(str);
	return (count);
}
