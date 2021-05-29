/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 04:20:02 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/29 13:46:37 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collection.h"
#include "libftprintf.h"
#include "events.h"

void	free_str(char **str)
{
	if (!*str)
		return ;
	free(*str);
	*str = NULL;
}

void	free_split(char ***split)
{
	char **array;

	if (!*split)
		return ;
	array = *split - 1;
	while (*(++array))
	{
		free(*array);
		*array = NULL;
	}
	free(*split);
	*split = NULL;
}

void	free_textures(t_texture *text)
{
	int			i;

	if (!(text))
		return ;
	i = -1;
	while (text[++i].array)
	{
		free(text[i].array);
		text[i].array = NULL;
	}
}

void	free_vars(t_vars *vars)
{
	int	i;

	i = -1;
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx && vars->img2[0].img)
		mlx_destroy_image(vars->mlx, vars->img2[0].img);
	if (vars->mlx && vars->img2[1].img)
		mlx_destroy_image(vars->mlx, vars->img2[1].img);
	free_split(&(vars->map.array));
	free_split(&(vars->map.tmp));
	free_textures(vars->text);
	free(vars->sprite_ptr);
	free(vars->gun.array);
	free(vars->flash.array);
	free(vars->z_buffer);
	while (++i < N_BARS)
		free((vars->health_bars[i]).array);
	i = -1;
	while (vars->text_paths[++i])
		free(vars->text_paths[i]);
	*vars = (t_vars){0};
	stop_sounds();
	play_sound(DEATH_SOUND);
}

void	free_cub(t_list **alst)
{
	if (!*alst)
		return ;
	ft_lstclear(alst, free);
	*alst = NULL;
}
