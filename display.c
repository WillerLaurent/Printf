/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 07:01:20 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/14 15:28:17 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display(char *str, t_opt a)
{
	int count;
	
	count = 0;
	if (a.type == 'c' && a.data[0] == 0 && ft_strlen(str) == 0)
	{
		ft_putchar_int(0);
		count++;
	}
	else
		count = ft_putstr_int(str);
	if (a.type == 'c' && a.data[0] == 0 && ft_strlen(str) > 0)
		count++;
	return (count);
}
