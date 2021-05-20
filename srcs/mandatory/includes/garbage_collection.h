/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collection.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:44:47 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:39:16 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTION_H
# define GARBAGE_COLLECTION_H

# include "structs/structs.h"
# include "libftprintf.h"
# include "mlx.h"

/*
** Useful garbage collection functions
*/

void	free_str(char **str);
void	free_split(char ***split);
void	free_textures(t_texture **t);

/*
** Cub3D specific functions
*/

void	free_vars(t_vars *vars);
void	free_cub(t_list **alst);

#endif
