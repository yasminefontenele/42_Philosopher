/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:28:33 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/27 07:27:17 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *routine(void *parameters)
{
    t_philo *philo;
    t_table *table;

    philo = (t_philo *)parameters;
    table = philo->table;
    
    if (philo->position % 2 && table->count_philo > 1)//se o filósofo for ímpar e houver mais de um filósofo
        time_check(table->time_to_eat / 50, table);//se o filósofo for ímpar, ele espera um pouco antes de comer
    while(!table->stop_condition && !table->max_ate)//executa até que a condição de parada seja atendida.
    {
        philo_eat(philo);
        print_philo("is sleeping", philo, UNLOCK);
        time_check(table->time_to_sleep, table);
        print_philo("is thinking", philo, UNLOCK);
        usleep(100);
    }
    return (NULL);
}

static void clear_threads(t_table *table)
{
    int i;
    
    if (table->count_philo == 1)
        pthread_detach(table->philos[0].philo_id);//se houver apenas um filósofo, ele é desanexado
    else
    {
        i = -1;
        while (++i < table->count_philo)
            pthread_join(table->philos[i].philo_id, NULL);//se houver mais de um filósofo, os filósofos são unidos
    }
    i = -1;
    while(++i < table->count_philo)
        pthread_mutex_destroy(&table->forks[i]);
    pthread_mutex_destroy(&table->count_meal);
    pthread_mutex_destroy(&table->writing);
    i = -1;
    while (++i < table->count_philo)
        free(table->philos[i].position_numb);
    free(table->philos);
    free(table->forks);
}

int init_threads(t_table *table)
{
    int i;

    i = -1;
    table->time_start = get_time();
    while(++i < table->count_philo)
    {
        table->philos[i].last_ate = get_time();
        if (pthread_create(&table->philos[i].philo_id, NULL, routine, &(table->philos[i])))
            return (0);
    }
    philo_dead(table, table->philos);
    pthread_mutex_unlock(&table->writing);
    clear_threads(table);
    return (1);
}