/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:00:12 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/04 11:57:33 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libftprintf/libftprintf.h"
# include <stdarg.h>

typedef struct	s_opt
{
	char name;
	char *type;
}				t_opt;


#endif