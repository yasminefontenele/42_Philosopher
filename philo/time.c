/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:26:41 by yasmine           #+#    #+#             */
/*   Updated: 2024/05/30 18:03:56 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**já faz parte da biblioeca <sys.time.h>
**struct timeval {
**    time_t      tv_sec;// segundos -> 1sec = 1000milisec 
**    suseconds_t tv_usec;//microssegundos -> 1micro == 0.001milisec
**};
**int   gettimeofday(struct timeval *, void *)
*/

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	diff_time(long long time)
{
	if (time > 0)
		return (get_time() - time);
	return (0);
}

void	exec_action(long long time)
{
	usleep(time * 1000);
}
