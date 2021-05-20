/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:33:40 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:47:20 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	ibool;

	i = 0;
	count = 0;
	ibool = 1;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (ibool == 1)
				count++;
			ibool = 0;
			i++;
		}
		ibool = 1;
	}
	return (count);
}

size_t	ft_splitlen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

char	*ft_splitdup(const char *str, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	if (!(word = (char *)malloc((ft_splitlen(str, c) + 1) * sizeof(char))))
		return (NULL);
	while (str[i] != c && str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_splitfree(char **base_split)
{
	size_t	i;

	i = 0;
	while (base_split[i])
	{
		free(base_split[i]);
		i++;
	}
	free(base_split);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**best_split;
	size_t	i;
	size_t	j;

	if (!s || (!s && !c))
		return (NULL);
	i = 0;
	j = 0;
	if (!(best_split = malloc((ft_count_words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (!(best_split[j] = ft_splitdup(s + i, c)))
				return (ft_splitfree(best_split));
			i += ft_splitlen(s + i, c);
			j++;
		}
	}
	best_split[j] = NULL;
	return (best_split);
}
