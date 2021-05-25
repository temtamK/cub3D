/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 04:20:29 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/25 15:00:06 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	turn_left(t_vars *vars, double speed)
{
	long double	old_dir_x;
	long double	old_plane_x;

	old_dir_x = vars->cam.dir_x;
	vars->cam.dir_x = vars->cam.dir_x * cos(speed)
		- vars->cam.dir_y * sin(speed);
	vars->cam.dir_y = old_dir_x * sin(speed)
		+ vars->cam.dir_y * cos(speed);
	old_plane_x = vars->cam.plane.x;
	vars->cam.plane.x = vars->cam.plane.x * cos(speed)
		- vars->cam.plane.y * sin(speed);
	vars->cam.plane.y = old_plane_x * sin(speed)
		+ vars->cam.plane.y * cos(speed);
}

void	turn_right(t_vars *vars, double speed)
{
	long double	old_dir_x;
	long double	old_plane_x;

	old_dir_x = vars->cam.dir_x;
	vars->cam.dir_x = vars->cam.dir_x * cos(-speed)
		- vars->cam.dir_y * sin(-speed);
	vars->cam.dir_y = old_dir_x * sin(-speed)
		+ vars->cam.dir_y * cos(-speed);
	old_plane_x = vars->cam.plane.x;
	vars->cam.plane.x = vars->cam.plane.x * cos(-speed)
		- vars->cam.plane.y * sin(-speed);
	vars->cam.plane.y = old_plane_x * sin(-speed)
		+ vars->cam.plane.y * cos(-speed);
}
