/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:30:19 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/29 14:22:36 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		check_surrounding(t_map *map, int x, int y, char *find)
{
	if (y > 0 && ft_strchr(find, map->array[y - 1][x]))
		return (0);
	else if (x < (map->x - 2) && ft_strchr(find, map->array[y][x + 1]))
		return (0);
	else if (y < (map->y - 2) && ft_strchr(find, map->array[y + 1][x]))
		return (0);
	else if (x > 0 && ft_strchr(find, map->array[y][x - 1]))
		return (0);
	return (1);
}

void	map_size(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (map->array[++y])
		if ((size_t)x < ft_strlen(map->array[y]))
			x = ft_strlen(map->array[y]);
	map->x = x;
	map->y = y;
}

int		duplicate_map(t_map *map)
{
	int	i;

	if (!(map->tmp = malloc(sizeof(char *) * map->y)))
		return (MALLOC_ERROR);
	i = 0;
	while (i < map->y)
	{
		if (!(map->tmp[i] = malloc(sizeof(char *) * (map->x + 1))))
			return (MALLOC_ERROR);
		ft_memcpy(map->tmp[i], map->array[i], map->x + 1);
		i++;
	}
	return (SUCCESS_CODE);
}
