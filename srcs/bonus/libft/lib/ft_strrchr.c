/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:37:22 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 07:41:33 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_strrchr(const char *source, int c)
{
	int	i;

	i = (int)ft_strlen(source) + 1;
	while (i--)
	{
		if (*(source + i) == (char)c)
			return ((char *)source + i);
	}
	return (0);
}

char	*ft_setrchr(char *str, char *charset)
{
	char	*found;
	char	*next;

	found = 0;
	while ((next = ft_setchr(str, charset)))
	{
		if (!*str)
			return (str);
		str++;
		if (!*next)
			return (next);
		found = next;
	}
	return (found);
}
