/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 15:41:26 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/09 17:05:41 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define UINT_MX 4294967296

int		ft_printf(char *format, ...);
int		pr_start(char fmt, va_list list);
int		pr_handle(char fmt, va_list list);
int		pr_ints(char fmt, va_list list);
int		pr_chars(char fmt, va_list list);
int		pr_base(char fmt, va_list list);
int		pr_wchars(char fmt, va_list list);
int		pr_cints(char fmt, va_list list);
int		pr_padd(va_list list);

int		pr_printaddress(void *n);
int		pr_putstr(char *s);
int		pr_putwstr(wchar_t *ws);
int		pr_putchar(char c);
int		pr_putwchar(wchar_t wc);
int		pr_putnbr(long n);
int		pr_putuint(long n);
int		ft_isalpha(int c);
int		pr_putcx(long x);
int		pr_putnbr_b(long n, int b);
char	*pr_itoa_b(long long n, int b);
char	*pr_itoa(long n);

#endif
