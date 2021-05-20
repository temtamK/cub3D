/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:50:24 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:47:20 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_atoi(const char *s)
{
	size_t		i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	while ((s[i] && (s[i] >= 9 && s[i] <= 13)) || s[i] == ' ')
		i++;
	sign = 1;
	if (s[i] && (s[i] == '+' || s[i] == '-'))
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && (s[i] >= '0') && (s[i] <= '9'))
	{
		num = num * 10 + (s[i++] - '0');
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
	}
	return (num * sign);
}
