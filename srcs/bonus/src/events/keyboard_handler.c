/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 04:20:49 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 04:20:50 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "garbage_collection.h"

int		forward_handler(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = (double)(vars->cam.x + vars->cam.dir_x * (vars->cam.speed));
	next_y = (double)(vars->cam.y + vars->cam.dir_y * (vars->cam.speed));
	if (key_chr(vars->keys, FORWARD_KEY, K_BUFF_SIZE))
	{
		if (vars->map.array[(int)next_x][(int)(vars->cam.y)] == '0'
		&& !sprite_collision(vars->sprites, next_x, vars->cam.y, ENNEMIES_TEX)
		&& !sprite_collision(vars->sprites, next_x, vars->cam.y, DOOR_TEX))
			vars->cam.x = next_x;
		if (vars->map.array[(int)(vars->cam.x)][(int)next_y] == '0'
		&& !sprite_collision(vars->sprites, vars->cam.x, next_y, ENNEMIES_TEX)
		&& !sprite_collision(vars->sprites, vars->cam.x, next_y, DOOR_TEX))
			vars->cam.y = next_y;
		return (1);
	}
	return (0);
}

int		backward_handler(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = (double)(vars->cam.x - vars->cam.dir_x * (vars->cam.speed));
	next_y = (double)(vars->cam.y - vars->cam.dir_y * (vars->cam.speed));
	if (key_chr(vars->keys, BACKWARD_KEY, K_BUFF_SIZE))
	{
		if (vars->map.array[(int)next_x][(int)(vars->cam.y)] == '0'
		&& !sprite_collision(vars->sprites, next_x, vars->cam.y, ENNEMIES_TEX)
		&& !sprite_collision(vars->sprites, next_x, vars->cam.y, DOOR_TEX))
			vars->cam.x = next_x;
		if (vars->map.array[(int)(vars->cam.x)][(int)next_y] == '0'
		&& !sprite_collision(vars->sprites, vars->cam.x, next_y, ENNEMIES_TEX)
		&& !sprite_collision(vars->sprites, vars->cam.x, next_y, DOOR_TEX))
			vars->cam.y = next_y;
		return (1);
	}
	return (0);
}

int		right_handler(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = (double)(vars->cam.x - (vars->cam.dir_y) * -(vars->cam.speed));
	next_y = (double)(vars->cam.y - (-vars->cam.dir_x) * -(vars->cam.speed));
	if (key_chr(vars->keys, RIGHT_KEY, K_BUFF_SIZE))
	{
		if (vars->map.array[(int)next_x][(int)(vars->cam.y)] == '0'
		&& !sprite_collision(vars->sprites, next_x, vars->cam.y, ENNEMIES_TEX))
			vars->cam.x = next_x;
		if (vars->map.array[(int)(vars->cam.x)][(int)next_y] == '0'
		&& !sprite_collision(vars->sprites, vars->cam.x, next_y, ENNEMIES_TEX))
			vars->cam.y = next_y;
		return (1);
	}
	return (0);
}

int		left_handler(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = (double)(vars->cam.x - (vars->cam.dir_y) * (vars->cam.speed));
	next_y = (double)(vars->cam.y - (-vars->cam.dir_x) * (vars->cam.speed));
	if (key_chr(vars->keys, LEFT_KEY, K_BUFF_SIZE))
	{
		if (vars->map.array[(int)next_x][(int)(vars->cam.y)] == '0'
		&& !sprite_collision(vars->sprites, next_x, vars->cam.y, ENNEMIES_TEX))
			vars->cam.x = next_x;
		if (vars->map.array[(int)(vars->cam.x)][(int)next_y] == '0'
		&& !sprite_collision(vars->sprites, vars->cam.x, next_y, ENNEMIES_TEX))
			vars->cam.y = next_y;
		return (1);
	}
	return (0);
}

int		alt_handler(t_vars *vars)
{
	t_camera	*cam;
	int			sprinting;

	sprinting = 0;
	cam = &(vars->cam);
	if (key_chr(vars->keys, ALT_KEY, K_BUFF_SIZE) && !sprinting)
	{
		cam->speed = ALT_MULT * SPEED;
		cam->turn_speed = ALT_MULT * TURN_SPEED;
		sprinting = 1;
	}
	else if (!sprinting)
	{
		cam->speed = SPEED;
		cam->turn_speed = TURN_SPEED;
	}
	else
		sprinting = 0;
	return (0);
}
