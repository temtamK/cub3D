/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:29:24 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/19 20:47:09 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "garbage_collection.h"

int		key_handler(int keycode, t_vars *vars)
{
	int i;

	i = -1;
	if (keycode == ESC_KEY)
	{
		free_vars(vars);
		exit(0);
	}
	i = -1;
	while (i < K_BUFF_SIZE && (((vars->keys)[i]).keycode != -1))
		i++;
	if (((vars->keys)[i]).keycode != -1)
		return (0);
	((vars->keys)[i]).keycode = keycode;
	while (++i < K_BUFF_SIZE)
		if (((vars->keys)[i]).keycode == keycode)
			((vars->keys)[i]).keycode = -1;
	return (0);
}

int		release_handler(int keycode, t_vars *vars)
{
	int				i;

	i = -1;
	while (++i < K_BUFF_SIZE)
	{
		if ((vars->keys[i]).keycode == keycode)
		{
			if (i >= K_BUFF_SIZE)
				return (0);
			((vars->keys)[i]).keycode = -1;
			((vars->keys)[i]).time = 0;
		}
	}
	return (0);
}

t_keys	*key_chr(t_keys *arr, int keycode, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		if (arr[i].keycode == keycode)
			return (arr + i);
	return (NULL);
}
