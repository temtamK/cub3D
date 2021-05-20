/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:48:10 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:39:16 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handler(t_infos infos, va_list *list)
{
	int ret;

	ret = 0;
	if (ft_strchr("pudixX", infos.conv) && infos.dot
		&& !get_curr_int(list))
	{
		(void)va_arg(*list, int);
		ret = (infos.pos == 'r') ? print_space_str(' ', infos.width -
			infos.precision - 2 * (infos.conv == 'p'), infos.printer) : 0;
		ret += (infos.conv == 'p') ? infos.printer(1, "0x", 2) : 0;
		ret += print_space_str('0', infos.precision, infos.printer);
		ret += (infos.pos == 'l') ? print_space_str(' ', infos.width -
			infos.precision - 2 * (infos.conv == 'p'), infos.printer) : 0;
		return (ret);
	}
	if (infos.width || infos.precision)
		return (print_space(&infos, list));
	return (print_conv(infos, list));
}

int	print_form(const char *format, va_list *list,
	ssize_t (*my_write)(int, const void *, size_t))
{
	char	*str;
	t_infos infos;

	if (!(str = ft_substr(format, 0,
		get_conv((char *)format) + 1 - format)))
		return (my_write(1, "ERROR", 5));
	infos = get_infos(str, list, (*my_write));
	free(str);
	return (handler(infos, list));
}
