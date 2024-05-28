/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:03:42 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/27 08:43:00 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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


int ft_checkint(const char *str_num)
{
    	int		i;
	int		neg;
	long	value;

	i = 0;
	value = 0;
	neg = 0;
	while ((str_num[i] == ' ' || (str_num[i] >= 9 && str_num[i] <= 13)))
		i++;
	if (str_num[i] == '-')
		neg = 1;
	if (str_num[i] == '-' || str_num[i] == '+')
		i++;
	while (str_num[i] != '\0' && (str_num[i] >= 48 && str_num[i] <= 57))
	{
		if (value > 214748364 || (value == 214748364
				&& ((!neg && str_num[i] - '0' > 7) || (neg && str_num[i] - '0' > 8))))
			return (0);
		else
			value = (value * 10) + str_num[i++] - '0';
	}
	return (1);
}

int ft_error(char *msg_error)
{
	write(2, msg_error, ft_strlen(msg_error));
	return (0);
}
