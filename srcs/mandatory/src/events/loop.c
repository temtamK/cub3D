/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:50:16 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/19 20:31:40 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "garbage_collection.h"

int		leave(t_vars *vars)
{
	free_vars(vars);
	exit(0);
}

void	hooks(t_vars *vars)
{
	mlx_hook(vars->win, KEY_PRESS, KEYPRESS_MASK, key_handler, (void *)vars);
	mlx_hook(vars->win, KEY_RELEASE, KEYRELEASE_MASK, release_handler,
			(void *)vars);
	mlx_hook(vars->win, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK, leave, vars);
	mlx_loop_hook(vars->mlx, loop_handler, (void *)vars);
}

int		loop_handler(t_vars *vars)
{
	static int	img = 0;
	int			i;

	i = -1;
	vars->redraw |= keyboard_handler(vars);
	while (++i < vars->num_sprites)
		vars->redraw |= vars->sprites[i].seen;
	if (vars->redraw)
	{
		draw_scene(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, (vars->img)->img, 0, 0);
		vars->img = vars->img2 + img;
		img = (img) ? 0 : 1;
		vars->redraw = 0;
	}
	return (0);
}
