/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:38:37 by yasmine           #+#    #+#             */
/*   Updated: 2024/05/30 17:13:27 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_table *table, int i)
{
	if (pthread_mutex_lock(&table->forks[table->philo[i].fork.left]) != 0)
		return (FALSE);
	if (philo_print(table, table->philo[i].philo_id, B_BLUE, FORK) == FALSE)
		return (FALSE);
	if (pthread_mutex_lock(&table->forks[table->philo[i].fork.right]) != 0)
		return (FALSE);
	if (philo_print(table, table->philo[i].philo_id, B_BLUE, FORK) == FALSE)
		return (FALSE);
	if (philo_print(table, table->philo[i].philo_id, G_CYAN, EAT) == FALSE)
		return (FALSE);
	table->philo[i].time_to_die = get_time();
	exec_action(table->args.time_to_eat);
	drop_forks(table, i);
	return (TRUE);
}

int	philo_sleep(t_table *table, int i)
{
	if (philo_print(table, table->philo[i].philo_id, BLUE, SLEEP) == FALSE)
		return (FALSE);
	exec_action(table->args.time_to_sleep);
	return (TRUE);
}

int	philo_think(t_table *table, int i)
{
	if (philo_print(table, table->philo[i].philo_id, G_BLUE, THINK) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	philo_is_dead(t_table *table, int *i)
{
	int	time;

	if (*i == table->args.nbr_philo)
		*i = 0;
	time = diff_time(table->philo[*i].time_to_die);
	if (time > table->args.time_to_die)
	{
		philo_print(table, table->philo[*i].philo_id, PINK, DIED);
		table->dead_philo = TRUE;
		return (TRUE);
	}
	i++;
	return (FALSE);
}

int	drop_forks(t_table *table, int i)
{
	if (pthread_mutex_unlock(&table->forks[table->philo[i].fork.left]))
		return (FALSE);
	if (pthread_mutex_unlock(&table->forks[table->philo[i].fork.right]))
		return (FALSE);
	table->philo[i].times_ate++;
	return (TRUE);
}
