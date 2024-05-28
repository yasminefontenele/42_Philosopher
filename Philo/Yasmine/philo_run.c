/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:43:19 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/27 08:28:23 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int ft_args(t_table *table, int ac, char **av)
{
    int i;

    i = 1;
    while(i < ac)
    {
        printf("Argument %d: %s\n", i, av[i]);
        if(!ft_checkint(av[i]) || ft_atoi(av[i]) <= 0 )//verifica se o argumento é um número
            return (0);
        i++;
    }
    table->count_philo = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        table->max_philo_eat = ft_atoi(av[5]);//se o argumento 6 existir, salva o valor
    else
        table->max_philo_eat = -1;//se não, salva 0
    printf("count_philo: %d\n", table->count_philo);
    printf("time_to_die: %d\n", table->time_to_die);
    printf("time_to_eat: %d\n", table->time_to_eat);
    printf("time_to_sleep: %d\n", table->time_to_sleep);
    printf("max_philo_eat: %d\n", table->max_philo_eat);
    if (table->count_philo <= 0 || table->time_to_die <= 0 || table->time_to_eat <= 0 || table->time_to_sleep <= 0)
    {
        printf("One or more parameters are invalid\n");
        return (0);
    }
    return(1);
}

int main(int ac, char **av)
{
    t_table table;

    table.max_ate = 0;//inicializa o contador de refeições
    table.stop_condition = 0;//inicializa a condição de parada
    if(ac < 5 || ac > 6)
        return(ft_error(ERROR_USAGE));
    if(!ft_args(&table, ac, av))
        return (ft_error("the parameters are incorrect\n"));
    if(!ft_init(&table))
        return (ft_error("init error\n"));
    if(!init_threads(&table))
        return (ft_error("thread error\n"));
    return (0);
}