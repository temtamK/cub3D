/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:24:16 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/29 14:38:31 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_color(char *line, unsigned char *dst)
{
	int		i;
	char	*trimmed __attribute__((cleanup(free_str)));
	int		nbr;

	i = -1;
	if (!line || !(trimmed = ft_strtrim(line, WHITESPACES)))
		return (MALLOC_ERROR);
	if (!*line)
		return (COLOR_ERROR);
	while (trimmed[++i])
		if (i > 3 || !ft_isdigit(trimmed[i]))
			return (COLOR_ERROR);
	nbr = ft_atoi(trimmed);
	if (nbr < 0 || nbr > 255)
		return (COLOR_ERROR);
	*dst = (unsigned char)(nbr);
	return (SUCCESS_CODE);
}

static int	count_char(char *str, char c)
{
	int i;
	int	count;

	i = -1;
	count = 0;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i] == c)
			count++;
	return (count);
}

int			return_color(t_vars *vars, char *line, unsigned char rgb[3])
{
	if (!ft_strncmp(line, "F ", 2) && !(vars->parser & PARSER_F))
	{
		vars->parser |= PARSER_F;
		vars->floor_color = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
		return (SUCCESS_CODE);
	}
	else if (!ft_strncmp(line, "C ", 2) && !(vars->parser & PARSER_C))
	{
		vars->parser |= PARSER_C;
		vars->roof_color = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
		return (SUCCESS_CODE);
	}
	return (COLOR_ERROR);
}

int			parse_color(char *line, t_vars *vars)
{
	char			**split __attribute__((cleanup(free_split)));
	char			*n_line;
	int				i;
	int				error;
	unsigned char	rgb[3];

	split = NULL;
	n_line = line + 2;
	if (count_char(n_line, ',') != 2)
		return (COLOR_ERROR);
	if (!(split = ft_split(n_line, ',')))
		return (MALLOC_ERROR);
	i = -1;
	while (split[++i])
	{
		if (i > 2)
			return (COLOR_ERROR);
		if ((error = check_color(split[i], rgb + i)) != SUCCESS_CODE)
			return (error);
	}
	if (i != 3)
		return (COLOR_ERROR);
	return (return_color(vars, line, rgb));
}
