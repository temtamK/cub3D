/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:47:55 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:39:16 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_conv(char *format)
{
	while (*format && !ft_strchr(CONV_TYPES, *format))
		format++;
	return ((*format) ? format : format - 1);
}

char	*get_format(char *format)
{
	while (*format && *format != '%')
		format++;
	return (format);
}
