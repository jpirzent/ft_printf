/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:52:02 by jpirzent          #+#    #+#             */
/*   Updated: 2018/07/09 14:03:13 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define INT_MA 4294967296
# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(char *format, ...);

#endif
