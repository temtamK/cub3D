/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 03:20:02 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 04:12:31 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

int	add_shade(double shade, int color)
{
	if (0 > shade || color == TRANS_COLOR)
		return (color);
	if (shade >= 1)
		return (0);
	((unsigned char *)&color)[0] *= (1.0 - shade);
	((unsigned char *)&color)[1] *= (1.0 - shade);
	((unsigned char *)&color)[2] *= (1.0 - shade);
	return (color);
}
