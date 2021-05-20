/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:43:11 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:47:20 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*n_dest;
	unsigned char	*n_src;
	size_t			position;

	position = -1;
	n_dest = dest;
	n_src = (unsigned char *)src;
	while (++position < n)
	{
		*(n_dest + position) = *(n_src + position);
		if (*(n_src + position) == (unsigned char)c)
			return (n_dest + position + 1);
	}
	return (NULL);
}
