/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:47:43 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:38:54 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

ssize_t		no_write(int filedes, const void *buf, size_t nbyte)
{
	(void)filedes;
	(void)buf;
	return (nbyte);
}

int			my_putchar(char c,
	ssize_t (*my_write)(int, const void *, size_t))
{
	return ((*my_write)(1, &c, 1));
}

static int	print_to_flag(char **str,
	ssize_t (*my_write)(int, const void *, size_t))
{
	int i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '%')
		i++;
	if ((*str)[i] && (*str)[i + 1] == '%')
	{
		i++;
		my_write(1, *str, i);
		*str += i + 1;
		return (i + print_to_flag(str, (*my_write)));
	}
	else if (i && (*str)[i - 1])
		my_write(1, *str, i);
	*str += i;
	return (i);
}

int			ft_vprintf(const char *format, va_list *list,
	ssize_t (*my_write)(int, const void *, size_t))
{
	int		printed;

	if (!format)
		return (my_write(1, "(null)", 6));
	printed = print_to_flag((char **)&format, (*my_write));
	while (*format)
	{
		printed += print_form(format, list, (*my_write));
		format = get_conv(((char *)format)) + 1;
		printed += (*format) ? print_to_flag((char **)&format, (*my_write)) : 0;
	}
	va_end(*list);
	return (printed);
}

int			ft_printf(const char *format, ...)
{
	va_list	list;

	if (!format)
		return (write(1, "(null)", 6));
	va_start(list, format);
	return (ft_vprintf(format, &list, write));
}
