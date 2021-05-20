/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:19:37 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:05:18 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "events_structs.h"
# include "parsing_structs.h"
# include "draw_structs.h"
# include "raycast_structs.h"
# include "sprites_structs.h"

# include <stdlib.h>

# define K_BUFF_SIZE 20
# define T_BUFF_SIZE 8
# define N_BARS		6

typedef struct		s_db_point
{
	double			x;
	double			y;
}					t_db_point;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
	t_screen		game_screen;
	t_map			map;
	t_data			*img;
	t_data			img2[2];
	t_camera		cam;
	t_keys			keys[K_BUFF_SIZE + 1];
	t_texture		text[T_BUFF_SIZE + 1];
	t_sprite		*sprites;
	t_texture		gun;
	t_texture		flash;
	t_spawn			spawn;
	int				floor_color;
	int				roof_color;
	char			*text_paths[T_BUFF_SIZE + 1];
	int				num_sprites;
	double			*z_buffer;
	int				redraw;
	int				seen_sprite;
	int				win_focus;
	int				draw_shot;
	int				frame_ready;
	t_texture		health_bars[N_BARS];
	int				hp;
	t_sprite		*sprite_ptr;
	double			pitch;
	double			pos_z;
}					t_vars;

typedef struct		s_bih
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bih;

#endif
