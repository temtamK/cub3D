/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 01:11:00 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/25 14:45:05 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "events.h"

int			init_img(void *mlx, int width, int height, t_data *img)
{
	*img = (t_data){0};
	if (!(img->img = mlx_new_image(mlx, width, height)))
		return (MLX_ERROR);
	img->addr = mlx_get_data_addr(img->img,
	&(img->bits_per_pixel), &(img->line_length), &(img->endian));
	img->width = width;
	img->height = height;
	return (SUCCESS_CODE);
}

int			init_cam(t_camera *cam, t_spawn *spawn)
{
	int				i;
	t_camera		cam_switcher[4];

	cam_switcher[0] = (t_camera){0.0, 0.0, -1.0, 0.0, SPEED, TURN_SPEED,
	(t_plane){0, 0.66}};
	cam_switcher[1] = (t_camera){0.0, 0.0, 1.0, 0.0, SPEED, TURN_SPEED,
	(t_plane){0, -0.66}};
	cam_switcher[2] = (t_camera){0.0, 0.0, 0.0, 1.0, SPEED, TURN_SPEED,
	(t_plane){0.66, 0.0}};
	cam_switcher[3] = (t_camera){0, 0, 0, -1.0, SPEED, TURN_SPEED,
	(t_plane){-0.66, 0.0}};
	i = 0;
	while (SPAWN_CHARS[i] && SPAWN_CHARS[i] != spawn->dir)
		i++;
	if (SPAWN_CHARS[i])
	{
		*cam = cam_switcher[i];
		cam->x = spawn->x;
		cam->y = spawn->y;
		return (SUCCESS_CODE);
	}
	*cam = (t_camera){0};
	return (MAP_ERROR);
}

int			init_textures(t_vars *vars)
{
	int		i;
	char	**text_paths;

	text_paths = vars->text_paths;
	i = -1;
	while (text_paths[++i])
		if (!ft_strnstr(text_paths[i] + ft_strlen(text_paths[i]) - 4,
			".xpm", 4))
			return (FILE_INVALID_ERROR);
	if (i != T_BUFF_SIZE)
		return (FILE_INVALID_ERROR);
	if (!(vars->text = malloc(sizeof(t_texture) * (i + 1))))
		return (MALLOC_ERROR);
	i = -1;
	while (text_paths[++i])
		if (load_texture(vars->text + i, text_paths[i], vars->mlx)
			!= SUCCESS_CODE)
		{
			vars->text[i] = (t_texture){0};
			free_textures(&(vars->text));
			return (TEXTURE_ERROR);
		}
	vars->text[i] = (t_texture) {0};
	return (SUCCESS_CODE);
}

static void	init_keys_buffer(t_keys *keys)
{
	int	i;

	i = -1;
	while (++i < K_BUFF_SIZE)
		keys[i] = (t_keys){-1, 0};
}

int			init_vars(char *path, t_vars *vars, int save)
{
	int				error;

	init_keys_buffer(vars->keys);
	if ((error = load_cub(path, vars)) != SUCCESS_CODE)
		return (error_print(error));
	if ((error = init_cam(&(vars->cam), &(vars->spawn))) != SUCCESS_CODE)
		return (error_print(error));
	if (!(vars->z_buffer = malloc(sizeof(double) * vars->game_screen.width)))
		return (MALLOC_ERROR);
	if (!(vars->mlx = mlx_init()))
		return (MLX_ERROR);
	check_resolution(vars->mlx,
		&vars->game_screen.width, &vars->game_screen.height);
	if (!save)
		if (!(vars->win = mlx_new_window(vars->mlx,
		vars->game_screen.width, vars->game_screen.height, WIN_NAME)))
			return (MLX_ERROR);
	if ((error = init_img(vars->mlx, vars->game_screen.width,
		vars->game_screen.height, vars->img2)) != SUCCESS_CODE)
		return (error_print(error));
	if ((error = init_img(vars->mlx, vars->game_screen.width,
		vars->game_screen.height, vars->img2 + 1)) != SUCCESS_CODE)
		return (error_print(error));
	return (error_print(init_textures(vars)));
}
