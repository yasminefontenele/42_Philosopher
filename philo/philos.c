/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:22:44 by yasmine           #+#    #+#             */
/*   Updated: 2024/06/24 13:26:38 by bruno            ###   ########.fr       */
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
	long long	now;
	int id = 1;
	
	table->start_time = get_time();
	now = diff_time(table->start_time);
	if (pthread_mutex_init(&table->print, NULL) != 0)
		return (FALSE);
	printf("%s %lld %d %s %s\n", B_BLUE, now, id, FORK, RESET);
	exec_action(table->args.time_to_die);
	printf("%s %lld %d %s %s\n", PINK, (long long int)table->args.time_to_die, id, DIED, RESET);
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
