/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 04:18:47 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 04:18:47 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"

int			get_n(int *init)
{
	static int	*n = NULL;

	if (init)
		n = init;
	return (*n);
}

void		swap_sprites(t_sprite *s1, t_sprite *s2)
{
	t_sprite	tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

double		s_dist(t_camera *cam, t_sprite *sprite)
{
	return ((cam->x - sprite->x) * (cam->x - sprite->x)
			+ (cam->y - sprite->y) * (cam->y - sprite->y));
}

/*
**	Insertion sort
*/

void		sort_sprites(t_camera *cam, t_sprite *arr, int n)
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
