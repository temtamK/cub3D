/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 04:19:40 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 05:50:26 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "frontend.h"

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

int			load_xpm(t_data *data, char *path, void *mlx)
{
	if (!data || !path || check_file(path) != SUCCESS_CODE)
		return (NULL_ERROR);
	if (!mlx)
		return (MLX_ERROR);
	*data = (t_data){0};
	data->img = mlx_xpm_file_to_image(mlx, path, &(data->width),
										&(data->height));
	if (!data->img)
		return (FILE_INVALID_ERROR);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
									&(data)->line_length, &(data)->endian);
	return (SUCCESS_CODE);
}

int			img_to_text(t_data *data, t_texture *text)
{
	int	x;
	int	y;

	x = -1;
	*text = (t_texture){0};
	if (!(text->array = malloc(sizeof(int) * data->width * data->height)))
		return (MALLOC_ERROR);
	text->width = data->width;
	text->height = data->height;
	while (++x < text->width)
	{
		y = -1;
		while (++y < text->height)
			text->array[text->width * y + x] = *(unsigned int *)
			(data->addr + (y * data->line_length + x *
			(data->bits_per_pixel / 8)));
	}
	return (SUCCESS_CODE);
}

int			load_texture(t_texture *text, char *path, void *mlx)
{
	t_data	data;
	int		error;

	*text = (t_texture){0};
	if (check_file(path) != SUCCESS_CODE)
		return (FILE_INVALID_ERROR);
	if (!text)
		return (TEXTURE_ERROR);
	if (load_xpm(&data, path, mlx) != SUCCESS_CODE)
		return (TEXTURE_ERROR);
	if (!data.addr || data.height <= 0 || data.width <= 0 || !data.img)
		return (MLX_ERROR);
	if ((error = img_to_text(&data, text)) != SUCCESS_CODE)
		*text = (t_texture){0};
	mlx_destroy_image(mlx, data.img);
	return (error);
}
