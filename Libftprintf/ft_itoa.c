/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 05:28:18 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/12 10:02:07 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*mk_str(char *str, long long n, int len)
{
	long long	nb;

	nb = n;
	if (nb < 0)
		nb = nb * (-1);
	while (len >= 0)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(long long n)
{
	int			len;
	long long	nb;
	char		*rtn;

	nb = n;
	len = 1;
	if (nb < 0)
	{
		nb = nb * (-1);
		len++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	if (!(rtn = malloc((len + 1) * sizeof(char))))
		return (NULL);
	rtn[len] = 0;
	len--;
	rtn = mk_str(rtn, n, len);
	return (rtn);
}
