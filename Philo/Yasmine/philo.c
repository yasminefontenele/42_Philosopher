/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:32:19 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/24 19:10:02 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void print_philo(char *msg, t_philo *philo, int unlock)
{
	char	*time_print;

	time_print = ft_itoa(get_time() - philo->table->time_start);
	pthread_mutex_lock(&philo->table->writing);
	if(!philo->table->stop_condition && !philo->table->max_philo_eat)
		printf("%s %s %s\n", time_print, philo->position_numb, msg);
	if (unlock)
		pthread_mutex_unlock(&philo->table->writing);
	free(time_print);
}

