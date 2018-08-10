/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:50:35 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/06 07:18:49 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		pr_printaddress(void *n)
{
	int		c;
	long	tmp;

	c = 0;
	tmp = (long)n;
	c = pr_putstr("0x");
	c += pr_putstr(pr_itoa_b(tmp, 16));
	return (c);
}
