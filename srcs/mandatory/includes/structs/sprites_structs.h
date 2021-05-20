/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:46:53 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/19 20:13:40 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_STRUCTS_H
# define SPRITES_STRUCTS_H

# include "structs.h"

typedef struct	s_sprite
{
	double		x;
	double		y;
	char		seen;
	int			tex_num;
}				t_sprite;

typedef struct	s_sprites_sorter
{
	int			sprite_order;
	double		sprite_distance;
}				t_sprites_sorter;

#endif
