/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:28:08 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/24 18:59:55 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static int	ft_init_mutex(t_table *table)
{
	int 	i;

	i = 0;
	while(i < table->count_philo)
	{
		if(pthread_mutex_init(&(table->forks[i]), NULL))
			return (1);
		i++;
	}
	if(pthread_mutex_init(&table->count_meal, NULL))
		return(1);
	if (pthread_mutex_init(&table->writing, NULL))
		return(1);
	return(0);
}

static int ft_init_philos(t_table *table)
{
	int	i;

	i = 0;
	while(i < table->count_philo)
	{
		table->philos[i].ate_times = 0;
		table->philos[i].position = i + 1;
		table->philos[i].position_numb = ft_itoa(i + 1);
		if(!table->philos[i].position_numb)
			break;
		table->philos[i].left_fork = i;
		table->philos[i].right_fork = (i + 1) % table->count_philo;
		table->philos[i].table = table;
	}
	if (i != table->count_philo)
	{
		while(i >= 0)
		{
			free(table->philos[i].position_numb);
			i--;
		}
		return(1);
	}
	return(0);
}

int	ft_init(t_table *table)
{
	table->philos = malloc(sizeof(t_philo) * table->count_philo);
	if(!table->philos)
		return(0);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->count_philo);
	if(!table->forks)
	{
		free(table->philos);
		return (0);
	}
	if(ft_init_mutex(table))
	{
		free(table->philos);
		free(table->forks);
		return(0);
	}
	if(ft_init_philos(table))
	{
		free(table->philos);
		free(table->forks);
		return(0);
	}
	return(1);
}