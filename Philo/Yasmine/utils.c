/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:03:42 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/21 17:41:03 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stddef.h>
#include <sys/time.h>

/*
já faz parte da biblioeca <sys.time.h>
struct timeval {
    time_t      tv_sec;// segundos
    suseconds_t tv_usec;//microssegundos
};

int   gettimeofday(struct timeval *, void *)
*/
unsigned long	get_time(void)
{
	struct timeval time;

    gettimeofday(&time, NULL);
	return((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));//dá o tempo total em milissegundos
}

void time_check(unsigned long duration, t_table *table)
{
	unsigned long	start;

	start = get_time();
	while(!table->stop_condition)
	{
		if(get_time() - start >= duration)
			break;
		usleep(table->count_philo * 2);
	}
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return(i);
}

int	ft_isint(const char *str_num)
{
	int i;
	int	signal;
	long	result;

	i = 0;
	signal = 0;
	result = 0;
	while(str_num[i] == ' ' || (str_num[i] >= 9 && str_num[i] <= 13))
		i++;
	if(str_num[i] == '-' || str_num[i] == '+')
	{
		if(str_num[i] == '-')
			signal *= -1;
		i++;
	}
	while(str_num[i] !=0 && (str_num[i] >= 48 && str_num[i]<= 57))
		if()
}