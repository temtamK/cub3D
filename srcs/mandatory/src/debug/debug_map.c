/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:04:59 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/19 20:13:40 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_map(char **array)
{
	int len;

	len = -1;
	if (!array)
		ft_putendl_fd("(NULL)", 2);
	while (array && array[++len])
		ft_putendl_fd(array[len], 2);
}
