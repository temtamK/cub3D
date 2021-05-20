/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 04:21:32 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 04:21:33 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int		my_mouse_get_pos(void *mlx, void *win, int *x, int *y)
{
	return (mlx_mouse_get_pos(mlx, win, x, y));
}

int		my_mouse_move(void *mlx, void *win, int x, int y)
{
	return (mlx_mouse_move(mlx, win, x, y));
}
