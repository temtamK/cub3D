/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 01:10:43 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/28 14:04:43 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "mlx.h"

int	get_conf(t_vars *vars, char *line)
{
	static char	*text_type[] = {"NO", "SO", "WE", "EA", "S ", 0};
	int			i;
	int			error;

	i = -1;
	error = SUCCESS_CODE;
	if (ft_strnstr(line, "R ", 2))
		error = parse_resolution(line + 2, &(vars->game_screen));
	else if (ft_strnstr(line, "F ", 2))
		vars->floor_color = parse_color(line + 2);
	else if (ft_strnstr(line, "C ", 2))
		vars->roof_color = parse_color(line + 2);
	else
		while (text_type[++i])
			if (ft_strnstr(line, text_type[i], 2))
				if (!(vars->text_paths[i] = ft_strtrim(line + 2, WHITESPACES)))
					return (MALLOC_ERROR);
	if (error != SUCCESS_CODE)
		return (error);
	vars->roof_color = (vars->roof_color == 0x1) ? 0 : vars->roof_color;
	vars->floor_color = (vars->floor_color == 0x1) ? 0 : vars->floor_color;
	return (SUCCESS_CODE);
}

int	check_resolution(void *mlx, int *width, int *height)
{
	int	max_width;
	int max_height;

	mlx_get_screen_size(mlx, &max_width, &max_height);
	*width = (*width > max_width) ? max_width : *width;
	*height = (*height > max_height) ? max_height : *height;
	return (SUCCESS_CODE);
}

int	parse_config(t_list *cub, t_vars *vars)
{
	char	*line __attribute__((cleanup(free_str)));
	int		error;

	line = NULL;
	if (!cub || !vars)
		return (NULL_ERROR);
	while (cub->next)
	{
		if (ft_replace_charset(cub->content, WHITESPACES, ' ') < 0)
			return (NULL_ERROR);
		if (!(line = ft_strtrim(cub->content, WHITESPACES)))
			return (MALLOC_ERROR);
		if ((error = get_conf(vars, line)) != SUCCESS_CODE)
			return (error);
		cub = cub->next;
		free(line);
		line = NULL;
	}
	if (vars->floor_color < 0 || vars->roof_color < 0)
		return (COLOR_ERROR);
	vars->text_paths[5] = NULL;
	return (SUCCESS_CODE);
}

int	read_cub(char *path, t_list **alst)
{
	char	*line;
	int		error;
	int		fd;
	int		len;

	if ((fd = open(path, O_RDONLY)) <= 0)
		return (FILE_INVALID_ERROR);
	*alst = NULL;
	len = 0;
	while ((((error = get_next_line(fd, &line)) == 1) || !error) && ++len)
	{
		if (!line)
		{
			close(fd);
			ft_lstclear(alst, free);
			return (MALLOC_ERROR);
		}
		ft_lstadd_back(alst, ft_lstnew(line));
		if (!error)
			break ;
	}
	close(fd);
	if (error < 0 || !*alst)
		return ((error < 0) ? error : NULL_ERROR);
	return (len);
}

void	map_size(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (map->array[++y])
		if ((size_t)x < ft_strlen(map->array[y]))
			x = ft_strlen(map->array[y]);
	map->x = x;
	map->y = y;
}

int		duplicate_map(t_map *map)
{
	int	i;

	if (!(map->tmp = malloc(sizeof(char *) * map->y)))
		return (MALLOC_ERROR);
	i = 0;
	while (i < map->y)
	{
		if (!(map->tmp[i] = malloc(sizeof(char *) * (map->x + 1))))
			return (MALLOC_ERROR);
		ft_memcpy(map->tmp[i], map->array[i], map->x + 1);
		i++;
	}
	return (SUCCESS_CODE);
}

int	load_cub(char *path, t_vars *vars)
{
	t_list	*cub __attribute__((cleanup(free_cub)));
	int		len;
	int		error;

	cub = NULL;
	if (!ft_strnstr(path + ft_strlen(path) - 4, CONF_FILE_EXTENSION, 4))
		return (WRONG_EXTENSION_ERROR);
	vars->map = (t_map){0};
	if ((len = read_cub(path, &cub)) <= 0)
		return (FILE_INVALID_ERROR);
	if ((error = parse_config(cub, vars)) != SUCCESS_CODE)
		return (error);
	if (!(vars->map.array = parse_array(cub, len)))
		return (MAP_ERROR);
	map_size(&(vars->map));
	if (find_spawn(&(vars->map), &(vars->spawn)) != SUCCESS_CODE)
		return (MAP_ERROR);
	if (parse_sprites(vars, vars->map.array, &(vars->num_sprites))
		!= SUCCESS_CODE)
		return (MAP_ERROR);
	if (duplicate_map(&(vars->map)) != SUCCESS_CODE)
		return (MALLOC_ERROR);
	check_borders(&(vars->map), vars->spawn.pos_x, vars->spawn.pos_y);
	if (vars->map.result == -3)
		return (MAP_ERROR);
	return (SUCCESS_CODE);
}
