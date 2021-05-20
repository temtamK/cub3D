/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:46:39 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/19 20:13:40 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_STRUCTS_H
# define PARSING_STRUCTS_H

/*
**	Useful graphic structs
*/

/*
**  s_data CONTAINS ALL THE DATA RELATED TO AN MLX IMAGE
*/

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_data;

typedef struct	s_texture
{
	int			*array;
	int			width;
	int			height;
	int			x;
	int			y;
}				t_texture;

typedef struct	s_screen
{
	int			width;
	int			height;
	int			x;
	int			y;
	t_data		*img;
}				t_screen;

/*
** cub3D specific structs
*/

typedef struct	s_spawn
{
	double	x;
	double	y;
	char	dir;
}				t_spawn;

typedef struct	s_map
{
	int			x;
	int			y;
	char		**array;
}				t_map;

#endif
