/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:04:28 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:47:20 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*new;

	if (!(new = malloc(size * num)))
		return (NULL);
	ft_memset(new, 0, size * num);
	return (new);
}
