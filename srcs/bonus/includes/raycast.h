/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:15:53 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/19 20:15:53 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "structs/structs.h"
# include "settings.h"
# include "sprites.h"

/*
** RAYCAST
*/

void	raycast_walls(t_ray *ray, t_vars *vars, int x) __attribute__((hot));
void	cast_sprites(t_sprite *s, t_camera *c, t_vars *v) __attribute__((hot));

void	perform_dda(t_vars *vars, t_ray *ray);
void	get_texture_coords(t_vars *vars, t_ray *ray);
void	get_texture_coords(t_vars *vars, t_ray *ray);
void	get_step(t_vars *vars, t_ray *ray);
void	init_raycast(t_vars *vars, int x, t_ray *ray);
void	put_sprites(t_vars *vars, t_sprite *sprites, t_camera *cam);

#endif
