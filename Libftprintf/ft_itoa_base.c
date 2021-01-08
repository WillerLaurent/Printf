/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:07:00 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/08 11:34:45 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char static	*ft_iota_base_2(int count, long int nb, char *rtn, char *base)
{
	unsigned int a;
	unsigned int ln_bs;

	ln_bs = ft_strlen(base);
	a = (nb >= 0) ? nb : nb * (-1);
	count--;
	rtn[count] = '\0';
	count--;
	while (count >= 0)
	{
		rtn[count] = base[a % ln_bs];
		a = a / ln_bs;
		count--;
		if (nb < 0)
			rtn[0] = '-';
	}
	return (rtn);
}
char		*ft_iota_base(long int nb, char *base)
{
	int				count;
	char			*rtn;
	unsigned int	ln_bs;
	unsigned int	a;

	count = 0;
	ln_bs = ft_strlen(base);
	a = (nb >= 0) ? nb : nb * (-1);
	count = (nb >= 0) ? 2 : 3;
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