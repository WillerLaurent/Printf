/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:59:34 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/12 16:42:55 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_substr(char *str, int start, int len)
{
	char			*sub_str;
	int				len_str;
	int				i;

	if (str == NULL)
		return (NULL);
	i = 0;
	len_str = ft_strlen(str);
	if (start >= len_str)
		return (ft_strdup(""));
	if (len > (len_str - start))
		len = len_str - start;
	if (!(sub_str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len && str[i + start])
	{
		sub_str[i] = str[i + start];
		i++;
	}
	sub_str[i] = 0;
	return (sub_str);
}
