/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:54:44 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:20:14 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"

void		draw_sprite_pxl(t_sprite_drawer *draw, int stripe, t_data *img)
{
	ssize_t	denom;
	int		y;

	y = draw->start_y - 1;
	while (++y < draw->end_y)
	{
		denom = (ssize_t)((y) * 256 + draw->factor_128);
		draw->text_y = ((denom * draw->text->width)
						/ (draw->sprite_height) / 256);
		draw->color = draw->text->array[(draw->text->width
		* draw->text_y + draw->text_x)];
		my_mlx_pixel_put(img, stripe, y, (SHADOW_MODE) ?
					add_shade(draw->shader, draw->color) : draw->color);
	}
}

void		draw_sprites(t_sprite_drawer *draw, t_sprite *sprites,
						double *sprites_depth, t_data *img)
{
	int	sprite;

	sprite = draw->start_x - 1;
	while (++sprite < draw->end_x)
	{
		draw->text_x = (int)(sprite * draw->pre_calc1 + draw->pre_calc2);
		if (draw->transform_y > 0 && sprite > 0 && sprite < draw->screen->width
			&& draw->transform_y < sprites_depth[sprite])
		{
			draw_sprite_pxl(draw, sprite, img);
			sprites[draw->sprite_index].seen = 1;
		}
		else
			sprites[draw->sprite_index].seen = 0;
	}
}

void		put_sprites(t_vars *vars, t_sprite *sprites, t_camera *cam)
{
	int				i;
	t_sprite		v_sprite;
	t_sprite_drawer	draw;

	draw = (t_sprite_drawer){0};
	draw.denom = 1.0 / (cam->plane.x * cam->dir_y - cam->dir_x * cam->plane.y);
	draw.screen = &(vars->game_screen);
	draw.half_win_height = draw.screen->height / 2;
	draw.half_win_width = draw.screen->width / 2;
	i = -1;
	while (++i < vars->num_sprites)
	{
		draw.sprite_index = i;
		v_sprite = sprites[draw.sprite_index];
		v_sprite.x -= cam->x;
		v_sprite.y -= cam->y;
		draw.dist = sqrt(v_sprite.x * v_sprite.x + v_sprite.y * v_sprite.y);
		if (draw.dist < 8 || !SHADOW_MODE)
		{
			init_sprite_drawing(&draw, cam, &v_sprite,
								vars->text + v_sprite.tex_num);
			draw_sprites(&draw, sprites, vars->z_buffer, vars->img);
		}
	}
}
