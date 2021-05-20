/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:44:36 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:57:26 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n_str;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(n_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_strlcpy(n_str, s1, s1_len + 1);
	ft_strlcat(n_str + s1_len, s2, s2_len + 1);
	return (n_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}

char	*ft_read(int fd, char **str)
{
	char	*buf;
	int		ret;
	char	*temp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || fd > 1024 || read(fd, buf, 0) < 0 || BUFFER_SIZE < 1)
	{
		free(buf);
		return (0);
	}
	if (*str == NULL)
		*str = ft_strdup("");
	while (!(ft_strchr(*str, '\n')))
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (0);
		buf[ret] = '\0';
		temp = ft_strjoin(*str, buf);
		free(*str);
		*str = temp;
		if (ret == 0)
			break ;
	}
	free(buf);
	return (*str);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[1024];
	char		*temp;
	char		*temp2;

	if (fd < 0 || fd > 1024 || !line || !(str[fd] = ft_read(fd, &str[fd])))
		return (-1);
	if ((temp = ft_strchr(str[fd], '\n')))
	{
		temp2 = str[fd];
		*line = ft_substr(str[fd], 0, temp - str[fd]);
		str[fd] = ft_strdup(str[fd] + (temp - str[fd]) + 1);
		free(temp2);
		return (1);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
}
