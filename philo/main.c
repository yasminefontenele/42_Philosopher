/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:09:17 by yasmine           #+#    #+#             */
/*   Updated: 2024/05/30 17:24:12 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (error_args(argc, argv, &table) == FALSE)
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
	ft_free(&table);
	return (0);
}
