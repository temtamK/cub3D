/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:54:49 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/19 20:13:40 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"

static void		swap_sprites(t_sprite *sprite_1, t_sprite *sprite_2)
{
	t_sprite	tmp;

	tmp = *sprite_1;
	*sprite_1 = *sprite_2;
	*sprite_2 = tmp;
}

static double	s_dist(t_camera *cam, t_sprite *sprite)
{
	return (((cam->x - sprite->x)
			* (cam->x - sprite->x)
			+ (cam->y - sprite->y)
			* (cam->y - sprite->y)));
}

/*
**	Insertion sort
*/

void			sort_sprites(t_camera *cam, t_sprite *arr, int n)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = i;
		while (j > 0 && s_dist(cam, arr + j - 1) < s_dist(cam, arr + j))
		{
			swap_sprites(arr + j, arr + j - 1);
			j--;
		}
		i++;
	}
}
