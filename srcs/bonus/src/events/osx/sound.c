/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 04:21:19 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 04:21:20 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	stop_sounds(void)
{
	return (system("(" KILL_COMMAND " " PLAYER " )" OPTIONS));
}

int	play_sound(char *path)
{
	char	command[1000];

	ft_bzero(command, 1000);
	ft_strlcat(command, "(" PLAYER " ", 1000);
	ft_strlcat(command, path, 1000);
	ft_strlcat(command, BACKGROUND ") " OPTIONS, 1000);
	return (system(command));
}
