/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:11:53 by yasmine           #+#    #+#             */
/*   Updated: 2024/05/30 17:23:02 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_args(int ac, char **av, t_table *table)
{
	if (ac == 2 && !ft_strncmp(av[1], "ERROR_USAGE", 11)
		&& ft_strlen(av[1]) == 11)
	{
		printf("%s%s%s\n", GREEN, ERROR_USAGE, RESET);
		return (FALSE);
	}
	else if (create_table(ac, av, table) == FALSE)
	{
		printf("%s%s%s\n", PINK, ERROR_USAGE, RESET);
		return (FALSE);
	}
	return (TRUE);
}
