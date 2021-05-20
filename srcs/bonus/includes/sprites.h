/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:15:26 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/19 20:15:30 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# include "structs/structs.h"
# include "settings.h"
# include "frontend.h"

void	swap_sprites(t_sprite *s1, t_sprite *s2);
void	sort_sprites(t_camera *c, t_sprite *s, int n) __attribute__((hot));
void	init_sprites_info(t_camera *c, t_sprite *sprites, int n)\
 __attribute__((hot));
void	init_sprite_drawing(t_sprite_drawer *d, t_camera *c,
				t_sprite *s, t_texture *t) __attribute__((hot));

#endif
