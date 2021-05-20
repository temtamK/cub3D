/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:46:30 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/19 20:13:40 by taemkim          ###   ########.fr       */
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
