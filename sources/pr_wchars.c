/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_wchars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:45:43 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/06 10:36:23 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pr_wchars(char fmt, va_list list)
{
	wchar_t		wc;
	wchar_t		*ws;

	if (fmt == 'C')
	{
		wc = va_arg(list, wchar_t);
		return (pr_putchar(wc));
	}
	else if (fmt == 'S')
	{
		ws = va_arg(list, wchar_t *);
		return (pr_putwstr(ws));
	}
	else
		return (-1);
}

int		pr_putwstr(wchar_t *ws)
{
	int		i;

	i = 0;
	while (ws[i])
	{
		pr_putchar(ws[i]);
		i++;
	}
	return (i);
}

int		pr_cints(char fmt, va_list list)
{
	long	n;

	if (fmt == 'D')
	{
		n = va_arg(list, long);
		return (pr_putnbr(n));
	}
	else if (fmt == 'U')
	{
		n = va_arg(list, long);
		return (pr_putuint(n));
	}
	else if (fmt == 'O')
	{
		n = va_arg(list, long);
		if (n < 0)
			n = UINT_MX - n;
		return (pr_putnbr_b(n, 8));
	}
	else
		return (-1);
}
