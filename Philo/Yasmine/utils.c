/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:03:42 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/24 15:21:26 by yfontene         ###   ########.fr       */
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


int	ft_checkint(const char *str_num)
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
	while(str_num[i] !=0 && (str_num[i] >= 0 && str_num[i]<= 9))
	{
		if(result > 214778364 || (result ==214748364 && ((!signal && str_num[i] - '0' > 7) || (signal && str_num[i] - '0' > '8'))))
			return(0);
		else
			result = (result * 10) + str_num[i++] - '0';
	}
	return (1);	
}

int ft_error(char *msg_error)
{
	write(2, msg_error, ft_strlen(msg_error));
	return (0);
}
