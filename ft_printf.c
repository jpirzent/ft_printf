/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:50:36 by jpirzent          #+#    #+#             */
/*   Updated: 2018/07/11 17:46:57 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"

void	ft_pudec(long l)
{
	if (l < 0)
	{
		l = l * -1;
		l = INT_MA - l;
	}
	ft_putnbrl(l);
}

int		ft_printf(char *format, ...)
{
	char			*s; //handling strings
	int				i; //handling integers
	long 			l; //handling uns ints
	int				c; //handling chars
	int				index;
	va_list			list;

	va_start(list, format);
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == 's')
			{
				s = va_arg(list, char *);
				ft_putstr(s);
			}
			else if (format[index + 1] == 'i')
			{
				i = va_arg(list, int);
				ft_putnbr(i);
			}
			else if (format[index + 1] == 'c')
			{
				c = va_arg(list, int);
				ft_putchar(c);
			}
			else if (format[index + 1] == 'u')
			{
				l = va_arg(list, int);
				ft_pudec(l);
			}
			else if (format[index + 1] == 'o')
			{
				i = va_arg(list, int);
				if (i > 0)
					ft_putbnbr(8, i);
			}
			else if (format[index + 1] == 'x')
			{
				i = va_arg(list, int);
				if (i > 0)
					ft_putbnbr(16, i);
				else
					ft_putbnbr(16, INT_MA + i);
			}
			else if (format[index + 1] == 'X')
			{
				i = va_arg(list, int);
				ft_putchex(i);
			}
			else if (format[index + 1] == 'd')
			{
				i = va_arg(list, int);
				ft_putnbr(i);
			}
			else if (format[index + 1] == 'D')
			{
				i = va_arg(list, int);
				ft_putD(i);
			}
			else if (format[index + 1] == '%')
				ft_putchar('%');
		}
		else if (format[index] != '%' && format[index - 1] != '%')
			ft_putchar(format[index]);
		index++;
	}
	va_end(list);
	return (0);
}

int		main(void)
{
	char			s[] = "#not";
	char			c = 'n';
	int				i = -8;
	unsigned int	u = -12300;
	int				o = 23;
	int				x = -31;
	int				X = -255;
	int				d = 2131;
	ft_printf("ft_printf:	james is cool  %s %i %o %c %u %x %X %d %% \n", s, i, o, c, u, x, X, d);
	printf("printf:		james is cool  %s %i %o %c %u %x %X %d %% \n", s, i, o, c, u, x, X, d);
}
