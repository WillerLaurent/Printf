/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_convert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:04:29 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/05 11:05:30 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		search_convert(char c)
{
	if (c == 'd' || c == 'i' || c == 'p' || c == 'c' || c == 's' || c == 'x' ||
	c == 'X' || c == 'u' || c == '%')
		return (1);
	return (0);
}

int		search_indicator(char c)
{
	if (c == '0' || c == '-' || c == '+')
		return (1);
	return (0);
}