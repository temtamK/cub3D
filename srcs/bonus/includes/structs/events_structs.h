/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:19:14 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/15 22:46:25 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_STRUCTS_H
# define EVENTS_STRUCTS_H
# include <time.h>

typedef struct	s_keys
{
	int			keycode;
	time_t		time;
}				t_keys;

#endif
