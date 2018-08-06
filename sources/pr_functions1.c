/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_functions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 16:44:47 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/06 13:47:39 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				pr_putnbr_b(long n, int base)
{
	char	*s;
	int		c;

	s = pr_itoa_b(n, base);
	c = pr_putstr(s);
	free(s);
	return (c);
}

static int		pr_conv(int n)
{
	if (n > 9)
		return (n - 10 + 'a');
	else
		return (n + '0');
}

char			*pr_itoa_b(long long n, int b)
{
	char			*s;
	int				l;
	long long		i;

	i = n;
	l = 0;
	if (n == 0)
		l++;
	else
		while (i > 0)
		{
			l++;
			i = i / b;
		}
	s = (char *)malloc(sizeof(char) * l);
	if (!s)
		return (NULL);
	s[l--] = '\0';
	while (l >= 0)
	{
		s[l] = pr_conv(n % b);
		l--;
		n = n / b;
	}
	return (s);
}

static int		pr_numlen(long n)
{
	int		i;

	i = 0;
	if (n == 0)
		i++;
	else
	{
		if (n < 0)
		{
			i++;
			n = n * -1;
		}
		while (n > 0)
		{
			i++;
			n = n / 10;
		}
	}
	return (i);
}

char			*pr_itoa(long n)
{
	int		i;
	char	*s;
	int		si;

	i = pr_numlen(n);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	si = 1;
	s[i--] = '\0';
	if (n < 0)
	{
		si = -1;
		n = n * -1;
	}
	if (n == 0)
		s[i--] = '0';
	else
		while (n > 0)
		{
			s[i--] = n % 10 + '0';
			n = n / 10;
		}
	if (si == -1)
		s[i--] = '-';
	return (s);
}
