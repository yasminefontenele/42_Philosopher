/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:22:44 by yasmine           #+#    #+#             */
/*   Updated: 2024/05/28 16:24:57 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philos(t_table *table)
{
	int	i;
	int	j;

	table->philo = malloc(sizeof(t_philo) * (table->args.nbr_philo + 1));
	if (table->philo == NULL)
		return (FALSE);
	i = 0;
	j = 1;
	while (j < table->args.nbr_philo)
	{
		fill_philo_struct(table, i, j);
		i++;
		j++;
	}
	j = 0;
	fill_philo_struct(table, i, j);
	return (TRUE);
}

void	fill_philo_struct(t_table *table, int i, int j)
{
	table->philo[i].philo_id = i + 1;
	table->philo[i].times_ate = 0;
	table->philo[i].time_to_die = 0;
	table->philo[i].fork.left = i;
	table->philo[i].fork.right = j;
}