/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 08:16:58 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/05 13:13:49 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(char *str)
{
	char	*cpy;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (!(cpy = malloc((len + 1) * sizeof(char))))
		return (NULL);
	cpy[len] = 0;
	len--;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	return (cpy);
}
