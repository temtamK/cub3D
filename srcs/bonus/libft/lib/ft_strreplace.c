/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 06:49:41 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:49:54 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_strreplace(char *src, char old, char new)
{
	size_t count;
	size_t i;

	count = 0;
	i = -1;
	if (!src)
		return (-1);
	while (src[++i])
		if (src[i] == old)
		{
			src[i] = new;
			count++;
		}
	return ((int)count);
}

int	ft_replace_charset(char *src, char *charset, char new)
{
	size_t	i;
	size_t	count;

	i = -1;
	count = 0;
	if (!src || !charset)
		return (-1);
	while (charset[++i])
		count += ft_strreplace(src, charset[i], new);
	return ((int)count);
}
