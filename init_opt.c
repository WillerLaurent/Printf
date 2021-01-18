/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:33:25 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/18 10:06:22 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_opt(t_opt *a)
{
	a->type = 0;
	a->indicator = 0;
	a->sign_neg = 0;
	a->sign_pos = 0;
	a->width = 0;
	a->precision = 0;
	a->prec_exist = 0;
	a->c_zero = 0;
	a->data = NULL;
	a->malloc_data = 0;
}
