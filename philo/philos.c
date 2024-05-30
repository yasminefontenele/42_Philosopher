/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:22:44 by yasmine           #+#    #+#             */
/*   Updated: 2024/05/30 18:03:49 by yfontene         ###   ########.fr       */
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
		philo_data(table, i, j);
		i++;
		j++;
	}
	j = 0;
	philo_data(table, i, j);
	return (TRUE);
}

void	philo_data(t_table *table, int i, int j)
{
	table->philo[i].philo_id = i + 1;
	table->philo[i].times_ate = 0;
	table->philo[i].time_to_die = 0;
	table->philo[i].fork.left = i;
	table->philo[i].fork.right = j;
}

int	just_one_philo(t_table *table)
{
	if (pthread_mutex_init(&table->print, NULL) != 0)
		return (FALSE);
	table->start_time = get_time();
	philo_print(table, 1, B_BLUE, FORK);
	exec_action(table->args.time_to_die);
	philo_print(table, 1, PINK, DIED);
	ft_free(table);
	return (TRUE);
}

int	create_table(int ac, char **av, t_table *table)
{
	if (ac == 5 || ac == 6)
	{
		table->args.nbr_philo = ft_atoi(av[1]);
		table->args.time_to_die = ft_atoi(av[2]);
		table->args.time_to_eat = ft_atoi(av[3]);
		table->args.time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			table->args.nbr_times_eat = ft_atoi(av[5]);
		else
			table->args.nbr_times_eat = -1;
		return (TRUE);
	}
	return (FALSE);
}
