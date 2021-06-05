/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:02:44 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/05 15:03:49 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_draw_square(t_vars *vars, int scale, int color)
{
	vars->map.max_x = vars->map.new_x + scale;
	while (vars->map.new_x < vars->map.max_x)
	{
		vars->map.new_y = vars->map.y * scale;
		while (vars->map.new_y < vars->map.max_y)
		{
			vars->tex.img_data[vars->map.new_x *
				vars->win.width + vars->map.new_y] = color;
			vars->map.new_y++;
		}
		vars->map.new_x++;
	}
}

void	ft_fill_data(t_vars *vars, int iswall, int color)
{
	int scale;

	scale = vars->win.width / 150;
	if (scale > 7)
		scale = 7;
	else if (scale < 5)
		scale = 5;
	vars->map.new_x = vars->map.x * scale;
	vars->map.new_y = vars->map.y * scale;
	vars->map.max_x = vars->map.new_x + scale;
	vars->map.max_y = vars->map.new_y + scale;
	if (iswall == 1)
		ft_draw_square(vars, scale, color);
	else
		ft_draw_square(vars, scale, color);
}

void	draw_player(t_vars *vars)
{
	vars->map.x = (int)vars->posx;
	vars->map.y = (int)vars->posy;
	ft_fill_data(vars, 0, RGB_RED);
}

int		ft_minimap(t_vars *vars)
{
	vars->map.x = 0;
	while (vars->map.x < vars->max_x)
	{
		vars->map.y = 0;
		while (vars->map.y < vars->max_y)
		{
			if (vars->worldmap[vars->map.x][vars->map.y] == '1')
				ft_fill_data(vars, 1, RGB_BLUE);
			else if (vars->worldmap[vars->map.x][vars->map.y] == '2')
				ft_fill_data(vars, 1, RGB_WHITE);
			else if (vars->worldmap[vars->map.x][vars->map.y] == '7')
				ft_fill_data(vars, 1, RGB_BLUE);
			else if (vars->worldmap[vars->map.x][vars->map.y] == '4')
				ft_fill_data(vars, 1, RGB_YELLOW);
			else if (vars->worldmap[vars->map.x][vars->map.y] == '0' ||
						vars->worldmap[vars->map.x][vars->map.y] == 'N')
				ft_fill_data(vars, 1, RGB_WHITE);
			else
				ft_fill_data(vars, 1, RGB_WHITE);
			vars->map.y++;
		}
		vars->map.x++;
	}
	draw_player(vars);
	return (0);
}
