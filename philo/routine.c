/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:28:28 by yasmine           #+#    #+#             */
/*   Updated: 2024/06/14 16:02:27 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_table	*table;
	int		i;

	table = (t_table *)args;
	i = table->nbr_threads;
	if (table->args.nbr_times_eat > 0)
	{
		while (table->args.nbr_times_eat > table->philo[i].times_ate
			&& table->dead_philo == FALSE)
			routine_execute(table, i);
	}
	else
	{
		while (table->dead_philo == FALSE)
		{
			if (routine_execute(table, i) == FALSE)
				break ;
		}
	}
	return (NULL);
}

int	routine_execute(t_table *table, int i)
{
	if (philo_eat(table, i) == FALSE)
		return (FALSE);
	if (table->args.nbr_times_eat != table->philo[i].times_ate)
	{
		if (philo_sleep(table, i) == FALSE)
			return (FALSE);
		if (philo_think(table, i) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

void	*checker_death(void *args)
{
	t_table	*table;
	int		i;

	table = (t_table *)args;
	i = 0;
	if (table->args.nbr_times_eat > 0)
	{
		while (table->args.nbr_times_eat > table->philo[i].times_ate
			&& table->dead_philo == FALSE)
		{
			if (philo_is_dead(table, &i) == TRUE)
				break ;
		}
	}
	else
	{
		while (table->dead_philo == FALSE)
		{
			if (philo_is_dead(table, &i) == TRUE)
				break ;
		}
	}
	return (NULL);
}

int	philo_print(t_table *table, int id, char *color, char *status)
{
	long long	now;

	now = diff_time(table->start_time);
	if (table->dead_philo == TRUE)
		return (FALSE);
	pthread_mutex_lock(&table->print);
	if (table->dead_philo == TRUE)
	{
		pthread_mutex_unlock(&table->print);
		return (FALSE);
	}
	else
		printf("%s %lld %d %s %s\n", color, now, id, status, RESET);
	pthread_mutex_unlock(&table->print);
	return (TRUE);
}
