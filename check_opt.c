/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:05:43 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/06 15:04:45 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_opt static check_precision(const char *input, t_opt a, int i, va_list *list)
{
	char *nbr;

	nbr = NULL;
	i++;
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
	return (a);
}

t_opt check_opt(const char *input, int i, t_opt a, va_list *list)
{
	char *nbr;

	nbr = calloc(1, sizeof(char));
	if (input[i] == '0' || input[i] == '-')
	{
		a.indicator = input[i];
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
		a = check_precision(input, a, i, list);
	if (seach_convert(input[i]))
		a.name = input[i];
	//printf("\na.width = %d\n", a.width);
	free(nbr);
	return (a);
}