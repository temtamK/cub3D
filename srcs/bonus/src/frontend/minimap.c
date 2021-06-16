/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:40:35 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/16 13:35:44 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

void	draw_square(t_vars *vars, t_minimap pos, int color)
{
	int	i;
	int	j;

	i = pos.y1;
	while (i < pos.y2)
	{
		j = pos.x1;
		while (j < pos.x2)
		{
			my_mlx_pixel_put(vars->img, j, i, color);
			j++;
		}
		i++;
	}
}

static void		render_player(t_vars *vars, t_spawn *player)
{
	t_minimap	pos;

	pos.x1 = player->pos_x * vars->minimap.scale + 12;
	pos.y1 = player->pos_y * vars->minimap.scale + 12;
	pos.x2 = pos.x1 + vars->minimap.scale;
	pos.y2 = pos.y1 + vars->minimap.scale;
	draw_square(vars, pos, 0xFF0000);
}

static void		render_minimap(t_vars *vars, t_map *map, int bool)
{
	int			j;
	int			i;
	int			width;

	i = -1;
	while (++i < map->y)
	{
		j = -1;
		width = ft_strlen(map->array[i]);
		while (++j < width)
		{
			vars->minimap.x1 = j * vars->minimap.scale + 12;
			vars->minimap.y1 = i * vars->minimap.scale + 12;
			vars->minimap.x2 = vars->minimap.x1 + vars->minimap.scale;
			vars->minimap.y2 = vars->minimap.y1 + vars->minimap.scale;
			if (map->array[i][j] == '0' && bool == 0)
				draw_square(vars, vars->minimap, 0xFFFFFF);
			else if (map->array[i][j] == '1' && bool == 0)
				draw_square(vars, vars->minimap, 0x0000FF);
			else if (map->array[i][j] == '2' && bool == 1)
				draw_square(vars, vars->minimap, 0xFFFF00);
		}
	}
}

void	init_minimap(t_vars *vars)
{
	int bigest_side;
	int scale;

	if ((vars->game_screen.width < 150 || vars->game_screen.height < 150) ||
		(vars->map.x < 5 || vars->map.y < 5))
	{
		vars->minimap.activate = 0;
		return ;
	}
	else
		vars->minimap.activate = 1;
	bigest_side = (vars->game_screen.width < vars->game_screen.height) ? vars->game_screen.width : vars->game_screen.height;
	if (vars->map.x < 14 || vars->map.y < 14)
		bigest_side /= 11;
	else
		bigest_side /= 4;
	scale = (vars->map.x > vars->map.y) ? bigest_side / vars->map.x
	: bigest_side / vars->map.y;
	vars->minimap.scale = (scale == 0) ? 1 : scale;
}

void			ft_minimap(t_vars *vars)
{
	init_minimap(vars);
	render_minimap(vars, &vars->map, 0);
	render_player(vars, &vars->spawn);
	if (vars->num_sprites > 0)
		render_minimap(vars, &vars->map, 1);
}
