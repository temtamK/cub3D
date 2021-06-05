/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:45:54 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/30 14:48:44 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collection.h"
#include "libftprintf.h"

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

void	free_textures(t_texture **t)
{
	t_texture	*text;
	int			i;

	if (!(text = *t))
		return ;
	i = -1;
	while (text[++i].array)
	{
		free(text[i].array);
		text[i].array = NULL;
	}
	free(text);
	*t = NULL;
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
	free_textures(&(vars->text));
	free(vars->sprites);
	free(vars->z_buffer);
	while (vars->text_paths[++i])
		free(vars->text_paths[i]);
}

void	free_cub(t_list **alst)
{
	if (!*alst)
		return ;
	ft_lstclear(alst, free);
	*alst = NULL;
}
