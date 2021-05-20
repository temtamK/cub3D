/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:48:30 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:39:16 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		wp_ft_vprintf(char *format,
	ssize_t (*my_write)(int, const void *, size_t), ...)
{
	va_list		lst;
	int			count;

	va_start(lst, my_write);
	count = ft_vprintf(format, &lst, my_write);
	va_end(lst);
	return (count);
}

int		get_curr_int(va_list *lst)
{
	va_list copy;
	int		arg;

	va_copy(copy, *lst);
	arg = (int)va_arg(copy, int);
	va_end(copy);
	return (arg);
}

t_infos	swp_printer(t_infos infos,
	ssize_t (*my_write)(int, const void *, size_t))
{
	infos.printer = (*my_write);
	return (infos);
}
