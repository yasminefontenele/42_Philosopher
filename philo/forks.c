/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:21:00 by yasmine           #+#    #+#             */
/*   Updated: 2024/05/30 17:54:57 by yfontene         ###   ########.fr       */
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
