/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 06:50:10 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:50:11 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t i;

	i = 0;
	while (i < maxlen && str[i])
		i++;
	return (i);
}
