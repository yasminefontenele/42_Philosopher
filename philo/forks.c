/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:21:00 by yasmine           #+#    #+#             */
/*   Updated: 2024/05/28 16:22:23 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->args.nbr_philo + 1);
	if (table->forks == NULL)
		return (FALSE);
	i = 0;
	while (i < table->args.nbr_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	unlock_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args.nbr_philo)
	{
		pthread_mutex_unlock(&table->forks[i]);
		i++;
	}
}