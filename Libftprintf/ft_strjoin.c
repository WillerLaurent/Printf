/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 07:12:11 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/05 13:21:18 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	str[0] = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	free(s1);
	s1 = NULL;
	return (str);
}

char	*ft_strjoin_left(char s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s2) + 2))))
		return (NULL);
	str[0] = 0;
	if (s1)
	{
		str[i] = s1;
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	free(s2);
	s2 = NULL;
	return (str);
}

char	*ft_strjoin_right(char *s1, char s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + 2))))
		return (NULL);
	str[0] = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	if (s2)
	{
		str[i + j] = s2;
		j++;
	}
	str[i + j] = 0;
	free(s1);
	s1 = NULL;
	return (str);
}
