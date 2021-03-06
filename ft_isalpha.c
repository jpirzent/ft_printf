/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:27:16 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/09 17:05:00 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isalpha(int c)
{
	if ((65 <= c && 90 >= c) || (97 <= c && 122 >= c))
		return (1);
	else
		return (0);
}
