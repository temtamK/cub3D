/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:19:25 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/19 20:19:29 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_STRUCTS_H
# define RAYCAST_STRUCTS_H

typedef struct	s_ray
{
	long double	dir_x;
	long double	dir_y;
	long double	side_dist_x;
	long double	side_dist_y;
	long double	delta_dist_x;
	long double	delta_dist_y;
	long double	perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			w_num;
	int			line_height;
	int			x;
	int			y;
}				t_ray;

typedef struct	s_pxl
{
	int			x;
	int			y;
	int			color;
}				t_pxl;

typedef struct	s_plane
{
	long double		x;
	long double		y;
}				t_plane;

typedef struct	s_camera
{
	long double		x;
	long double		y;
	long double		dir_x;
	long double		dir_y;
	double			speed;
	double			turn_speed;
	t_plane			plane;
	int				hp;
}				t_camera;

#endif
