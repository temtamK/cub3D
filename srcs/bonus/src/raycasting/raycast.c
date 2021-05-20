/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 04:19:14 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 04:19:14 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "garbage_collection.h"

void	init_raycast(t_vars *vars, int x, t_ray *ray)
{
	long double	camera_x;

	camera_x = 2 * x / (long double)vars->game_screen.width - 1.0;
	ray->dir_x = vars->cam.dir_x + vars->cam.plane.x * camera_x;
	ray->dir_y = vars->cam.dir_y + vars->cam.plane.y * camera_x;
	ray->x = (int)(vars->cam.x);
	ray->y = (int)(vars->cam.y);
	ray->delta_dist_x = fabsl(1 / ray->dir_x);
	ray->delta_dist_y = fabsl(1 / ray->dir_y);
	ray->hit = 0;
}

void	get_step(t_vars *vars, t_ray *ray)
{
	if (ray->dir_x < 0)
		ray->side_dist_x = (vars->cam.x - ray->x) * ray->delta_dist_x;
	else
		ray->side_dist_x =
			(ray->x + 1.0 - vars->cam.x) * ray->delta_dist_x;
	if (ray->dir_y < 0)
		ray->side_dist_y = (vars->cam.y - ray->y) * ray->delta_dist_y;
	else
		ray->side_dist_y =
			(ray->y + 1.0 - vars->cam.y) * ray->delta_dist_y;
	ray->step_x = (ray->dir_x < 0) ? -1 : 1;
	ray->step_y = (ray->dir_y < 0) ? -1 : 1;
}

void	perform_dda(t_vars *vars, t_ray *ray)
{
	while (ray->hit == 0)
	{
		ray->side = !(ray->side_dist_x < ray->side_dist_y);
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->x += ray->step_x;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->y += ray->step_y;
		}
		ray->hit = (((vars->map.array)[ray->x][ray->y] - '0') > 0);
	}
}

void	get_texture_coords(t_vars *vars, t_ray *ray)
{
	double wall_x;

	if (ray->side == 0)
		wall_x = vars->cam.y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = vars->cam.x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor((wall_x));
	vars->text[ray->w_num].x = (int)
		(wall_x * (double)(vars->text[ray->w_num].width));
	if (ray->side == 0 && ray->dir_x > 0)
		vars->text[ray->w_num].x = vars->text[ray->w_num].width
									- vars->text[ray->w_num].x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		vars->text[ray->w_num].x = vars->text[ray->w_num].width
									- vars->text[ray->w_num].x - 1;
}

void	cast_sprites(t_sprite *sprites, t_camera *cam, t_vars *vars)
{
	vars->seen_sprite = 0;
	sort_sprites(cam, sprites, vars->num_sprites);
	put_sprites(vars, sprites, cam);
}
