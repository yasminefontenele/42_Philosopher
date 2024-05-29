/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:39:41 by yasmine           #+#    #+#             */
/*   Updated: 2024/05/29 09:58:32 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_table *table)
{
	int	i;

	i = 0;
	table->dead_philo = FALSE;
	table->start_time = get_time();
	if (pthread_mutex_init(&table->print, NULL) != 0)
		return (FALSE);
	while (i < table->args.nbr_philo)
	{
		table->nbr_threads = i;
		if (pthread_create(&table->philo[i].thread,
				NULL, &routine, (void *) table) != 0)
			return (FALSE);
		i++;
		usleep(1000);
	}
	if (pthread_create(&table->waiter, NULL, &checker, (void *) table) != 0)
		return (FALSE);
	usleep(1000);
	if (join_threads(table) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args.nbr_philo)
	{
		if (pthread_join(table->philo[i].thread, NULL) != 0)
			return (FALSE);
		i++;
	}
	if (pthread_join(table->waiter, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

int	destroy_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args.nbr_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->print);
	return (TRUE);
}