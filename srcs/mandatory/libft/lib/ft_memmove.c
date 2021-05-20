/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:41:17 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:47:20 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*n_dest;
	unsigned char	*n_src;
	size_t			pst;

	if (dest == src || len == 0)
		return (dest);
	pst = -1;
	n_dest = (unsigned char *)dest;
	n_src = (unsigned char *)src;
	if (n_src < n_dest)
		while ((int)(--len) >= 0)
			*(n_dest + len) = *(n_src + len);
	else
		while (++pst < len)
			*(n_dest + pst) = *(n_src + pst);
	return (dest);
}
