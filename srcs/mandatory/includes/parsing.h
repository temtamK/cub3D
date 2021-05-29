/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:45:05 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/29 14:27:38 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <unistd.h>
# include "structs/structs.h"
# include "../libft/libftprintf.h"
# include "garbage_collection.h"
# include "settings.h"

# define VALID_CONF_IDS		"NSWEFC\n"
# define VALID_MAP_CHARS	"012NSEW "
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

/*
**  IMAGE PARSING
*/

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
int		check_surrounding(t_map *map, int x, int y, char *find);
int		duplicate_map(t_map *map);
void	check_borders(t_map *map, int x, int y);
int		find_spawn(t_map *map, t_spawn *spawn);
char	**parse_array(t_list *lst, int len);
int		init_vars(char *path, t_vars *vars, int save);
int		load_cub(char *path, t_vars *vars);
int		parse_sprites(t_vars *vars, char **map, int *size);

#endif
