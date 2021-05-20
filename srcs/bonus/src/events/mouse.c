/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 04:20:33 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 04:20:34 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <limits.h>

int		mouse_press_handler(int keycode, int x, int y, t_vars *vars)
{
	(void)(x && y);
	if (keycode == 1)
		return (key_handler(LEFT_CLICK, vars));
	return (key_handler(-1, vars));
}

int		mouse_release_handler(int keycode, int x, int y, t_vars *vars)
{
	(void)(x && y);
	if (keycode == 1)
		return (release_handler(LEFT_CLICK, vars));
	return (release_handler(-1, vars));
}

int		click_handler(t_vars *vars)
{
	static clock_t	last_shot = 0;
	double			elapsed;
	static int		released = 1;

	elapsed = (double)(clock() - last_shot) / (double)CLOCKS_PER_SEC;
	if (!key_chr(vars->keys, LEFT_CLICK, K_BUFF_SIZE)
		&& !key_chr(vars->keys, SHOOT_KEY, K_BUFF_SIZE))
		released = 1;
	else if (elapsed > (double)SHOT_DURATION && released)
	{
		released = 0;
		if (elapsed > (double)SHOT_DURATION + (double)SHOT_COOLDOWN)
		{
			last_shot = clock();
			vars->draw_shot = 1;
			play_sound(GUNSHOT_PATH);
			shoot_sprites(&(vars->sprites), &(vars->num_sprites));
			return (1);
		}
	}
	if (elapsed > (double)SHOT_DURATION && vars->draw_shot)
		vars->draw_shot = 0;
	return (0);
}

void	get_center(t_vars *vars, int *center_x, int *center_y)
{
	static int	center[2] = {INT_MIN, INT_MIN};

	if (center[0] == INT_MIN)
	{
		center[0] = vars->game_screen.width / 2;
		center[1] = vars->game_screen.height / 2;
		if (OSX)
		{
			my_mouse_move(vars->mlx, vars->win, vars->game_screen.width / 2,
						vars->game_screen.height / 2);
			my_mouse_get_pos(vars->mlx, vars->win, center + 0, center + 1);
		}
	}
	*center_x = center[0];
	*center_y = center[1];
}

int		mouse_move_handler(t_vars *vars)
{
	int			win_xy[2];
	int			center[2];
	double		i;
	int			foo;

	foo = 0;
	get_center(vars, center, center + 1);
	if (!vars->win_focus)
		return (0);
	my_mouse_get_pos(vars->mlx, vars->win, win_xy, win_xy + 1);
	if (((i = (double)win_xy[1] - vars->game_screen.height / 2)
				!= vars->game_screen.height / 2))
	{
		vars->pitch -= i * 2;
		check_pitch(&(vars->pitch));
		foo = 1;
	}
	if ((i = (double)win_xy[0] - center[0]) != (center[0]))
	{
		turn_right(vars, i / MOUSE_DPI);
		foo = 1;
	}
	if (foo)
		my_mouse_move(vars->mlx, vars->win, center[0], center[1]);
	return (1);
}
