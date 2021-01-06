/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 07:01:20 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/06 15:29:01 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static display_zero_left(t_opt a, char *str, int count)
{
	if (a.width > ft_strlen(str))
		a.width = a.width - ft_strlen(str);

	while (a.width > 0)
	{
		str = ft_strjoin_left('0', str);
		a.width--;
	}
	count = ft_putstr_int(str);
	free(str);
	return (count);
}

int static display_pad_right(t_opt a, char *str, int count)
{
	if (a.width > ft_strlen(str))
		a.width = a.width - ft_strlen(str);
	while (a.width > 0)
	{
		str = ft_strjoin_right(str, ' ');
		a.width--;
	}
	count = ft_putstr_int(str);
	free(str);
	return (count);
}

int static display_pad_left(t_opt a, char *str, int count)
{
	//	printf("\n2a.width = %d\n", a.width);

	if (a.width > ft_strlen(str))
		a.width = a.width - ft_strlen(str);
	while (a.width > 0)
	{
		str = ft_strjoin_left(' ', str);
		a.width--;
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

//faire la chaine complete puis l'afficher
	count = 0;
	result = 0;
	str = NULL;
	result = va_arg(*list, int);
	str = ft_itoa(result);
	if (a.indicator == '0')
		count = display_zero_left(a, str, count);
	else if (a.width > 0 && a.indicator == '-')
		count = display_pad_right(a, str, count);
	else if (a.width > 0 && a.indicator != '-')
		count = display_pad_left(a, str, count); 
	else
		count  = ft_putstr_int(str);
	return (count);
}

int display(t_opt a, va_list *list)
{
	int count;

	count = 0;
	if (a.name == 'd' || a.name == 'i')
		count = display_d(a, list);
	return (count);
}