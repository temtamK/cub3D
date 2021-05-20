/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:19:32 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/19 20:19:33 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_STRUCTS_H
# define SPRITES_STRUCTS_H

# include "structs.h"

typedef struct	s_sprite
{
	double		x;
	double		y;
	char		seen;
	int			tex_num;
	int			hp;
}				t_sprite;

#endif
