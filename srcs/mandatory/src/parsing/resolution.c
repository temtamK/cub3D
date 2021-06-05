/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:24:16 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/05 14:26:30 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <limits.h>

int			check_resolution(void *mlx, int *width, int *height)
{
	int	max_width;
	int max_height;

	mlx_get_screen_size(mlx, &max_width, &max_height);
	*width = (*width > max_width) ? max_width : *width;
	*height = (*height > max_height) ? max_height : *height;
	return (SUCCESS_CODE);
}

static int	get_parsed_res(char **split, t_screen *screen)
{
	int		i;
	int		j;

	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			if (!ft_isdigit(split[i][j]))
				return (RESOLUTION_ERROR);
			if (j > 9 || (j == 9 && split[i][0] > 2))
			{
				screen->width = INT_MAX;
				screen->height = INT_MAX;
				return (SUCCESS_CODE);
			}
		}
	}
	if (i != 2)
		return (RESOLUTION_ERROR);
	screen->width = ft_atoi(split[0]);
	screen->height = ft_atoi(split[1]);
	return (SUCCESS_CODE);
}

int			parse_resolution(char *line, t_vars *vars)
{
	char	**split __attribute__((cleanup(free_split)));

	if (!(split = ft_split(line, ' ')))
		return (MALLOC_ERROR);
	if (get_parsed_res(split, &(vars->game_screen)) != SUCCESS_CODE)
		return (RESOLUTION_ERROR);
	if (vars->game_screen.width < 0 || vars->game_screen.height < 0)
		return (RESOLUTION_ERROR);
	vars->parser |= PARSER_R;
	return (SUCCESS_CODE);
}
