/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 04:20:24 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 04:20:25 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "garbage_collection.h"

int		leave(t_vars *vars)
{
	free_vars(vars);
	exit(0);
	return (0);
}

void	check_pitch(double *ptr)
{
	if (ptr)
	{
		if (*ptr < MIN_PITCH)
			*ptr = MIN_PITCH;
		if (*ptr > MAX_PITCH)
			*ptr = MAX_PITCH;
	}
}
