/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:07:00 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/12 16:44:23 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_iota_base_2(int i, unsigned long long nb, char *rtn, char *base)
{
	unsigned long long	a;
	unsigned int		ln_bs;

	ln_bs = ft_strlen(base);
	a = nb;
	i--;
	rtn[i] = '\0';
	i--;
	while (i >= 0)
	{
		rtn[i] = base[a % ln_bs];
		a = a / ln_bs;
		i--;
	}
	return (rtn);
}

char		*ft_iota_base(unsigned long long nb, char *base)
{
	int					count;
	char				*rtn;
	unsigned int		ln_bs;
	unsigned long long	a;

	count = 0;
	ln_bs = ft_strlen(base);
	a = nb;
	count = 2;
	while (a > ln_bs - 1)
	{
		a = a / ln_bs;
		count++;
	}
	if (!(rtn = malloc(count * sizeof(char))))
		return (0);
	rtn = ft_iota_base_2(count, nb, rtn, base);
	return (rtn);
}
