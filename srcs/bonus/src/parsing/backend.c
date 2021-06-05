/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 04:19:50 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/05 14:38:52 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "mlx.h"

int	parser_check(t_vars *vars, char *line)
{
	if (!ft_strncmp(line, "R ", 2) && (vars->parser & PARSER_R))
		return (RESOLUTION_ERROR);
	else if (!ft_strncmp(line, "NO ", 3) && (vars->parser & PARSER_NO))
		return (CONFIG_ERROR);
	else if (!ft_strncmp(line, "SO ", 3) && (vars->parser & PARSER_SO))
		return (CONFIG_ERROR);
	else if (!ft_strncmp(line, "WE ", 3) && (vars->parser & PARSER_WE))
		return (CONFIG_ERROR);
	else if (!ft_strncmp(line, "EA ", 3) && (vars->parser & PARSER_EA))
		return (CONFIG_ERROR);
	else if (!ft_strncmp(line, "S ", 2) && (vars->parser & PARSER_S))
		return (CONFIG_ERROR);
	else if (!ft_strncmp(line, "F ", 2) && (vars->parser & PARSER_F))
		return (COLOR_ERROR);
	else if (!ft_strncmp(line, "C ", 2) && (vars->parser & PARSER_C))
		return (COLOR_ERROR);
	return (SUCCESS_CODE);
}

int	get_conf(t_vars *vars, char *line)
{
	static char	*text_type[] = {"NO", "SO", "WE", "EA", "S ", "DC", "EN", "DO",
								0};
	static int	parser_type[] = {PARSER_NO, PARSER_SO, PARSER_WE,
								PARSER_EA, PARSER_S,
								PARSER_DC, PARSER_EN, PARSER_DO, 0};
	int			i;

	i = -1;
	if (ft_strnstr(line, "R ", 2) && !(vars->parser & PARSER_R))
		return (parse_resolution(line + 2, vars));
	else if (ft_strnstr(line, "F ", 2) || !(vars->parser & PARSER_F)
			|| ft_strnstr(line, "C ", 2) || !(vars->parser & PARSER_C))
		return (parse_color(line, vars));
	else
		while (text_type[++i])
			if (ft_strnstr(line, text_type[i], 2) &&
				!(vars->parser & parser_type[i]))
			{
				vars->text_paths[i] = ft_strtrim(line + 2, WHITESPACES);
				vars->parser |= parser_type[i];
				return (SUCCESS_CODE);
			}
	if (!vars->game_screen.height || !vars->game_screen.width)
	{
		vars->game_screen.width = 1280;
		vars->game_screen.height = 800;
	}
	return (parser_check(vars, line));
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
	vars->text_paths[T_BUFF_SIZE] = NULL;
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
	while ((error = get_next_line(fd, &line)) == 1)
	{
		(len)++;
		if (line)
			ft_lstadd_back(alst, ft_lstnew(line));
		else
			ft_lstclear(alst, free);
	}
	free(line);
	close(fd);
	if (error != SUCCESS_CODE || !*alst)
		return ((error != SUCCESS_CODE) ? error : NULL_ERROR);
	return (len);
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
	return (vars->map.result);
}
