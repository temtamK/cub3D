/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:30:19 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/30 14:23:39 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	format_map_line(char *line)
{
	int i;
	int j;

	i = 0;
	if (!line || !*line)
		return ((line) ? SUCCESS_CODE : MAP_ERROR);
	while (ft_strchr(WHITESPACES, line[i]))
		line[i] = '0';
	while (line[i++])
	{
		if (ft_isspace(line[i]))
			line[i] = '0';
		if (!ft_strchr(VALID_MAP_CHARS, line[i]))
			return (MAP_ERROR);
	}
	j = ft_strlen(line);
	while (ft_strchr(WHITESPACES, line[--j]))
		line[i] = '0';
	return (SUCCESS_CODE);
}

char		**parse_array(t_list *lst, int len)
{
	char	**array;
	int		error;

	error = 0;
	if (lst && lst->content && (array = ft_calloc((len + 1), sizeof(char *))))
	{
		len = 1;
		while (lst && lst->content
			&& ((lst->next && (!ft_isdigit(*(char *)lst->content)
			&& !ft_isspace(*(char *)lst->content))) || !*(char *)lst->content))
			lst = lst->next;
		if (!(error = !lst))
		{
			array[0] = ft_strdup(lst->content);
			error |= format_map_line(array[0]);
			while ((lst = lst->next) && *(char *)lst->content
					&& !(error |= format_map_line(lst->content)))
				array[len++] = ft_strdup(lst->content);
		}
	}
	else
		array = NULL;
	if (error || len <= 2)
		free_split(&array);
	return (array);
}

int			find_spawn(t_map *map, t_spawn *spawn)
{
	char	*spawn_ptr;
	char	*last_ptr;
	int		x;

	x = -1;
	*spawn = (t_spawn){-1, -1, 0, 0, 0};
	while (map && map->array[++x])
	{
		if ((spawn_ptr = ft_setchr(map->array[x], SPAWN_CHARS))
						!= (last_ptr = ft_setrchr(map->array[x], SPAWN_CHARS)))
			return (MAP_ERROR);
		else if (spawn_ptr)
		{
			*spawn = (t_spawn){x + 0.5, spawn_ptr - map->array[x] + 0.5,
			map->array[x][spawn_ptr - map->array[x]],
			spawn_ptr - map->array[x], x};
			map->array[(int)(spawn->x - 0.5)][(int)(spawn->y - 0.5)] = VOID;
		}
	}
	if (spawn->x <= 0 || spawn->y <= 0 || !ft_strchr(SPAWN_CHARS, spawn->dir))
		return (MAP_ERROR);
	return (SUCCESS_CODE);
}

void		check_borders(t_map *map, int x, int y)
{
	if (!(ft_strchr("NSEW", map->tmp[y][x])))
		map->tmp[y][x] = 'F';
	if (!(x) || !(y) || y == (map->y - 1) ||
		x == (map->x - 1) || !check_surrounding(map, x, y, "\0"))
	{
		map->result = -3;
		return ;
	}
	if (y > 0 && ft_strchr("0234", map->tmp[y - 1][x]))
		check_borders(map, x, y - 1);
	if ((y < (map->y - 1)) && ft_strchr("0234", map->tmp[y + 1][x]))
		check_borders(map, x, y + 1);
	if ((x < (map->x - 1)) && ft_strchr("0234", map->tmp[y][x + 1]))
		check_borders(map, x + 1, y);
	if (x > 0 && ft_strchr("0234", map->tmp[y][x - 1]))
		check_borders(map, x - 1, y);
}
