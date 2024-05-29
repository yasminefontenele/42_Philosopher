/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:09:17 by yasmine           #+#    #+#             */
/*   Updated: 2024/05/28 16:11:25 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (error_handling(argc, argv, &table) == FALSE)
		return (1);
	if (create_philos(&table) == FALSE)
		return (1);
	if (create_forks(&table) == FALSE)
		return (1);
	if (table.args.nbr_philo == 1)
	{
		if (just_one_philo(&table) == FALSE)
			return (1);
		return (0);
	}
	if (create_threads(&table) == FALSE)
		return (1);
	if (destroy_threads(&table) == FALSE)
		return (1);
	philo_free(&table);
	return (0);
}

int	just_one_philo(t_table *table)
{
	if (pthread_mutex_init(&table->print, NULL) != 0)
		return (FALSE);
	table->start_time = get_time();
	philo_print(table, 1, B_BLUE, FORK);
	exec_action(table->args.time_to_die);
	philo_print(table, 1, PINK, DIED);
	philo_free(table);
	return (TRUE);
}