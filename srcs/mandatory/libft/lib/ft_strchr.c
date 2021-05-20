/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:40:23 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 07:31:07 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_strchr(const char *source, int c)
{
	char	chr;
	int		i;

	chr = (unsigned char)c;
	i = 0;
	while (source[i] != '\0')
	{
		if (source[i] == chr)
			return ((char *)source + i);
		i++;
	}
	if (source[i] == chr)
		return ((char *)source + i);
	return (0);
}

char	*ft_setchr(const char *str, char *charset)
{
	char	*found;
	int		i;

	i = -1;
	if (!charset)
		return (0);
	while (charset[++i])
		if ((found = ft_strchr(str, charset[i])))
			return (found);
	return (0);
}
