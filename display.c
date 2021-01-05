/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 07:01:20 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/05 14:02:03 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static display_zero_left(t_opt a, char *str, int count)
{
	if (a.nb_zero > ft_strlen(str))
		a.nb_zero = a.nb_zero - ft_strlen(str);

	while (a.nb_zero > 0)
	{
		str = ft_strjoin_left('0', str);
		a.nb_zero--;
	}
	count = ft_putstr_int(str);
	free(str);
	return (count);
}
int static display_pad(t_opt a, char *str, int count)
{
	if (a.pad_left > ft_strlen(str))
		a.pad_left = a.pad_left - ft_strlen(str);

	while (a.pad_left > 0)
	{
		str = ft_strjoin_left(' ', str);
		a.pad_left--;
	}
	count = ft_putstr_int(str);
	free(str);
	return (count);
}

int display_d(t_opt a, va_list *list)
{
	int count;
	char *str;
	int result;

	count = 0;
	result = 0;
	str = NULL;
	result = va_arg(*list, int);
	str = ft_itoa(result);
	if (a.pad_left > 0)
		count = display_pad(a, str, count);
	else if (a.nb_zero > 0)
		count = display_zero_left(a, str, count);
	return (count);
}

int display(t_opt a, va_list *list)
{
	int count;

	count = 0;
	if (a.name == 'd')
		count = display_d(a, list);
	return (count);
}