/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:09:45 by lwiller           #+#    #+#             */
/*   Updated: 2021/01/11 16:43:00 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static check_input(const char *input, va_list *list, int i)
{
	int count;
	t_opt a;
	char *str;

	count = 0;
	str = NULL;
	init_opt(&a);
	a = check_opt(input, i, a, list);
	str = make_string(a, str);
	count = display(str, a);
	if (ft_strlen(str) > 0)
		free(str);
	return (count);
}

int static read_string(const char *input, va_list *list)
{
	int count_char;
	int count_var;
	int i;

	count_char = 0;
	count_var = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] != '%')
			count_char += ft_putchar_int(input[i]);
		if (input[i] == '%')
		{
			i++;
			count_var = check_input(input, list, i);
			count_char += count_var;
			while (search_convert(input[i]) == 0)
				i++;
		}
		i++;
	}
	return (count_char);
}

int ft_printf(const char *input, ...)
{
	va_list list;
	int result;

	va_start(list, input);
	result = read_string(input, &list);
	va_end(list);
	return (result);
}

int main()
{
	int ret;
	int i;

	i = -1;
	ret = ft_printf("Moi : |%16.2x|", -24);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%016.2x|", -24);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%16.4X|", -24);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%16.4X|", -24);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);


	ret = ft_printf("Moi : |%3%|");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%3%|");
	printf("LuiR : ret = |%d|\n", ret);
	i++;
	ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%16.2u|", -24);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%16.2u|", -24);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%16.2u|", 24);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%16.2u|", 24);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%16.2u|", 2468);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%16.2u|", 2468);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%16.2u|", 2);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%16.2u|", 2);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%-45.0u|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-45.0u|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%45.0u|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%45.0u|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%0.0u|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%0.0u|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);
//10

	ret = ft_printf("Moi : |%0.0d|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%0.0d|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%0.0x|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%0.0x|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%-10.8X|%d|%5.4d|%x|%X|d|", -1, 123, 456, 7, 8);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-10.8X|%d|%5.4d|%x|%X|d|", -1, 123, 456, 7, 8);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%-10.8X|%-10.8d|%5.4d|%x|%X|d|", -1, 123, 456, 7, 8);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-10.8X|%-10.8d|%5.4d|%x|%X|d|", -1, 123, 456, 7, 8);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%-10.8X|", -1);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-10.8X|", -1);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%.x|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.x|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%-10.8X|", -12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-10.8X|", -12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%10d|", -12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%10d|", -12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%10.6d|", -12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%10.6d|", -12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%10.7d|", -12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%10.7d|", -12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

//20
	ret = ft_printf("Moi : |%10.8d|", -12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%10.8d|", -12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%-10.8d|", -12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-10.8d|", -12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("|%10c|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("|%10c|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%.s|", NULL);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.s|", NULL);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%.s|", "NULL");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.s|", "NULL");
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%.d|", 10);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.d|", 10);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%.d|", 1230);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.d|", 1230);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%.d|", -1230);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.d|", -1230);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%12p|", (void *)123456);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%12p|", (void *)123456);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%-12p|", (void *)123456);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-12p|", (void *)123456);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);
//30

	ret = ft_printf("Moi : |%.p|", NULL);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.p|", NULL);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%c|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%c|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%5c|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%5c|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%10x|", 12399);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%10x|", 12399);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%x|", 12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%x|", 12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%d|", 12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%d|", 12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%*.17d|", 25, 12354);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%*.17d|", 25, 12354);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%.15d|", 10);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.15d|", 10);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%2d|", 10142);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%2d|", 10142);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	//40
	ret = ft_printf("Moi : |%*d|", 10, 10142);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%*d|", 10, 10142);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%.2s|", NULL);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.2s|", NULL);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%s|", "NULL");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%s|", "NULL");
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%10s|", "NULL");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%10s|", "NULL");
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%d|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%d|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%.d|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.d|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%x|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%x|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%.x|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.x|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%p|", (void *)0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%p|",  (void *)0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%.p|",  (void *)0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.p|",  (void *)0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	//50

	ret = ft_printf("Moi : |%0d|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%0d|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%01d|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%01d|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	/*ret = ft_printf("Moi : |%010d|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%010d|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%010x|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%010x|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%1.10d|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%1.10d|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	
	ret = ft_printf("Moi : |%*.*d|", -12, 7, 12);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%*.*d|", -12, 7, 12);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);
	
	ret = ft_printf("Moi : |%*.*d|", -12, -7, 12);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%*.*d|", -12, -7, 12);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%*.*d|", 12, -7, 12);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%*.*d|", 12, -7, 12);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%*.*d|", 54, 0, 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%*.*d|", 54, 0, 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);


	

	ret = ft_printf("Moi : |%.2s|", "NULL");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.2s|", "NULL");
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);*/
//60
	/*ret = ft_printf("Moi : |%s|", "NULL");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%s|", "NULL");
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%10s|", "NULL");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%10s|", "NULL");
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);
	


	ret = ft_printf("Moi : |%.46s|", NULL);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%.46s|", NULL);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%54.0d|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%54.0d|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%010.0d|", 0);
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%010.0d|", 0);
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%20s|", "fvTymR0e24eqIVl9OqR7F6gUKPQFjG1I5b8JHUL1");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%20s|", "fvTymR0e24eqIVl9OqR7F6gUKPQFjG1I5b8JHUL1");
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%20s|", "Ai0S3P6gQ6zK18MhR21ZQUHo7dfPnNyGr7yXbS0ohPhKYIHM9DObr");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%20s|", "Ai0S3P6gQ6zK18MhR21ZQUHo7dfPnNyGr7yXbS0ohPhKYIHM9DObr");
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);



	ret = ft_printf("Moi : |%-2s|",  "bonjour");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%-2s|",  "bonjour");
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%54.0s|", "7q4ZwnFmXmIivQFRMgxXDRy1pL6BNElfmac");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%54.0s|", "7q4ZwnFmXmIivQFRMgxXDRy1pL6BNElfmac");
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);

	ret = ft_printf("Moi : |%54.1s|", "7q4ZwnFmXmIivQFRMgxXDRy1pL6BNElfmac");
	ft_printf("MoiR : ret = |%d|\n", ret);
	ret = printf("Lui : |%54.1s|", "7q4ZwnFmXmIivQFRMgxXDRy1pL6BNElfmac");
	printf("LuiR : ret = |%d|\n", ret);
	i++;ft_printf("i = %d\n\n-------------------\n\n", i);*/
}