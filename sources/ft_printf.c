/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:36:12 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/06 12:42:39 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list		list;
	int			i;
	int			temp;
	int			c;

	va_start(list, format);
	i = 0;
	c = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			temp = pr_handle(format[i + 1], list);
			if (temp == -1)
				exit(0);
			else
				c += temp;
		}
		else if (format[i] != '%' && format[i - 1] != '%')
			c += pr_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (c);
}
