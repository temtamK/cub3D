/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:37:19 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 04:12:31 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "frontend.h"
#include "settings.h"

static void	get_color(t_drawer *draw, t_texture *tex)
{
	tex->y = (int)draw->tex_pos & (tex->height - 1);
	draw->tex_pos += draw->step;
	if (!tex->array || (tex->height * tex->y + tex->x)
						> tex->height * tex->width)
		return ;
	else
		draw->color = tex->array[tex->height * tex->y + tex->x];
}

void		draw_col(t_vars *vars, t_drawer *draw)
{
	while (++draw->y < draw->screen->height)
	{
		if (draw->start <= draw->y && draw->y <= draw->end)
		{
			get_color(draw, &(vars->text[draw->side]));
			if (SHADOW_MODE)
				draw->color = add_shade(((double)draw->dist / 16 * 2),
				draw->color);
		}
		if (draw->y > draw->end)
		{
			draw->color = draw->floor_color;
			if (SHADOW_MODE)
				draw->color = add_shade(1.05 / ((double)draw->y * 2.15
				/ (double)((draw->screen->height))), draw->color);
		}
		my_mlx_pixel_put(vars->img, draw->x, draw->y, draw->color);
	}
}

void		init_drawer(t_drawer *draw, t_ray *ray, int text_height)
{
	draw->line_height = (int)(draw->screen->height / ray->perp_wall_dist);
	draw->start = -(draw->line_height) / 2 + draw->screen->height / 2;
	draw->end = (draw->line_height) / 2 + draw->screen->height / 2;
	draw->color = draw->roof_color;
	draw->y = -1;
	draw->dist = ray->perp_wall_dist;
	draw->side = ray->w_num;
	draw->start = (draw->start < 0) ? 0 : draw->start;
	draw->end = (draw->end >= draw->screen->height)
				? draw->screen->height - 1 : draw->end;
	draw->step = 1.0 * text_height / draw->line_height;
	draw->tex_pos = (draw->start - draw->screen->height / 2
					+ draw->line_height / 2) * draw->step;
}

void		draw_scene(t_vars *vars)
{
	t_ray		ray;
	t_drawer	draw;

	draw = (t_drawer)
	{
		0, .x = -1, .screen = &(vars->game_screen),
		.floor_color = vars->floor_color, .roof_color = vars->roof_color
	};
	while (++(draw.x) < draw.screen->width)
	{
		raycast_walls(&ray, vars, draw.x);
		init_drawer(&draw, &ray, vars->text[ray.w_num].height);
		draw_col(vars, &draw);
	}
	cast_sprites(vars->sprites, &(vars->cam), vars);
}

void		draw_text(t_texture *text, t_data *img, int x0, int y0)
{
	int	x;
	int	y;

	x = -1;
	while (++x < text->width)
	{
		y = -1;
		while (++y < text->height)
			my_mlx_pixel_put(img, x + x0, y + y0,
							text->array[text->width * y + x]);
	}
}
