/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:04:03 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/29 21:23:06 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return (0);
	write(fd, s, ft_strlen(s));
	return (1);
}
