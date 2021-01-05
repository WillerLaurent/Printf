/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:53:55 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/04 15:56:33 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	is_whispace(char c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == '\f' ||
			c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int				i;
	int				sign;
	int				result;

	i = 0;
	result = 0;
	sign = 1;
	while (is_whispace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
