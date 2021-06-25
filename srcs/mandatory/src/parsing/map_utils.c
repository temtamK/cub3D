/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:30:19 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/25 15:19:15 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		check_surrounding(t_map *map, int x, int y)
{
	if (y > 0 && map->tmp[y + 1][x] == '\0')
		return (0);
	else if (x < (map->x - 2) && map->tmp[y][x + 1] == '\0')
		return (0);
	else if (y < (map->y - 2) && map->tmp[y + 1][x] == '\0')
		return (0);
	else if (x > 0 && map->tmp[y][x + 1] == '\0')
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
	int		i;
	int		j;

	if (!(map->tmp = malloc(sizeof(char *) * (map->y + 1))))
		return (MALLOC_ERROR);
	i = -1;
	while (++i < map->y)
	{
		if (!(map->tmp[i] = malloc(sizeof(char *) * (map->x))))
			return (MALLOC_ERROR);
		j = -1;
		while (map->array[i][++j])
			map->tmp[i][j] = map->array[i][j];
		while (j < map->x)
			map->tmp[i][j++] = '0';
		map->tmp[i][j] = '\0';
	}
	map->tmp[i] = NULL;
	return (SUCCESS_CODE);
}
