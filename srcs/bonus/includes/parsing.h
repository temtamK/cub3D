/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:15:58 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/28 14:55:00 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include "structs/structs.h"
# include "../libft/libftprintf.h"
# include "garbage_collection.h"
# include "settings.h"

# define ASPECT_RATIO 0.6

# define GUN_PATH   "pics/small_gun.xpm"
# define FLASH_PATH "pics/muzzle.xpm"

# define BAR_1_PATH "pics/bars/bar_2_.xpm"
# define BAR_2_PATH	"pics/bars/bar_3_.xpm"
# define BAR_3_PATH	"pics/bars/bar_4_.xpm"
# define BAR_4_PATH	"pics/bars/bar_5_.xpm"
# define BAR_5_PATH	"pics/bars/bar_6_.xpm"
# define BAR_6_PATH	"pics/bars/bar_7_.xpm"

# define VALID_CONF_IDS		"NSWEFC\n"
# define VALID_MAP_CHARS	"01234NSEW "
# define CONF_FILE_EXTENSION ".cub"
# define WIN_NAME "cub3D"
# define STDERR 2
# define PARSER_R 0x00001
# define PARSER_NO 0x00002
# define PARSER_SO 0x00004
# define PARSER_EA 0x00008
# define PARSER_WE 0x00010
# define PARSER_S 0x00020
# define PARSER_F 0x00040
# define PARSER_C 0x00080
# define PARSER_DC 0x00100
# define PARSER_EN 0x00200
# define PARSER_DO 0x00400

/*
**  IMAGE PARSING
*/

int		init_img(void *mlx, int width, int height, t_data *img);
int		load_xpm(t_data *data, char *path, void *mlx);
int		load_texture(t_texture *text, char *path, void *mlx);
int		img_to_text(t_data *data, t_texture *text);

/*
**  Reusable conf parsing function
*/

int		check_resolution(void *mlx, int *width, int *height);
int		parse_resolution(char *line, t_vars *vars);
int		parse_color(char *line, t_vars *vars);

/*
**  Cub3D specific functions
*/
void	map_size(t_map *map);
int		check_surrounding(t_map *map, int x, int y);
int		duplicate_map(t_map *map);
void	check_borders(t_map *map, int x, int y);
int		find_spawn(t_map *map, t_spawn *spawn);
char	**parse_array(t_list *lst, int len);
int		init_vars(char *path, t_vars *vars, int save);
int		load_cub(char *path, t_vars *vars);
int		parse_sprites(t_vars *vars, char **map, int *size);

#endif
