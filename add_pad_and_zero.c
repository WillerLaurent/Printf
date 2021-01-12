/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pad_and_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:37:43 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/12 15:46:39 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_pad_left(char *str, int size)
{
	int len_str;

	len_str = ft_strlen(str);
	if (size >= len_str)
		size = size - len_str;
	else if (size < len_str)
		size = len_str;
	while (size > 0)
	{
		str = ft_strjoin_left(' ', str);
		size--;
	}
	return (str);
}

char	*add_pad_right(char *str, int size)
{
	int len_str;

	len_str = ft_strlen(str);
	if (size > len_str)
		size = size - len_str;
	else if (size < len_str)
		size = len_str;
	while (size > 0)
	{
		str = ft_strjoin_right(str, ' ');
		size--;
	}
	return (str);
}

char	*add_zero_left(char *str, int size)
{
	int len_str;

	len_str = ft_strlen(str);
	if (size > len_str)
		size = size - len_str;
	else if (size < len_str)
		size = len_str;
	while (size > 0)
	{
		str = ft_strjoin_left('0', str);
		size--;
	}
	return (str);
}
