/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:33:25 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/06 12:58:02 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_opt(t_opt *a)
{
	a->name = 0;
	a->indicator = 0;
	a->nb_zero = 0;
	a->width = 1;//valeurs : -1 = *, par defaut = 1
	a->precision = -2; //valeurs : -1 = *, -2 par defaut
}