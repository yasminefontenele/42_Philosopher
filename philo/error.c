/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:11:53 by yasmine           #+#    #+#             */
/*   Updated: 2024/05/28 16:20:28 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handling(int ac, char **av, t_table *table)
{
	if (ac == 2 && !philo_strncmp(av[1], "ERROR_USAGE", 11)
		&& philo_strlen(av[1]) == 11)
	{
		printf("%s%s%s\n", GREEN, ERROR_USAGE, RESET);
		return (FALSE);
	}
	else if (init_input_struct(ac, av, table) == FALSE)
	{
		printf("%s%s%s\n", PINK, ERROR_USAGE, RESET);
		return (FALSE);
	}
	return (TRUE);
}

int	init_input_struct(int ac, char **av, t_table *table)
{
	if (ac == 5 || ac == 6)
	{
		table->args.nbr_philo = philo_atoi(av[1]);
		table->args.time_to_die = philo_atoi(av[2]);
		table->args.time_to_eat = philo_atoi(av[3]);
		table->args.time_to_sleep = philo_atoi(av[4]);
		if (ac == 6)
			table->args.nbr_times_eat = philo_atoi(av[5]);
		else
			table->args.nbr_times_eat = -1;
		return (TRUE);
	}
	return (FALSE);
}