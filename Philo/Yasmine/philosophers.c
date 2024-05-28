/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:32:19 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/27 07:24:10 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_philo(char *msg, t_philo *philo, int unlock)
{
	char	*time_print;

	time_print = ft_itoa(get_time() - philo->table->time_start);
	pthread_mutex_lock(&philo->table->writing);
	if(!philo->table->stop_condition && !philo->table->max_ate)
		printf("%s %s %s\n", time_print, philo->position_numb, msg);
	if (unlock)
		pthread_mutex_unlock(&philo->table->writing);
	free(time_print);
}

//Simula o ato de um filósofo pegar os garfos, comer, e depois liberar os garfos
void philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->left_fork]);//pega o garfo da esquerda
	print_philo("has taken a fork", philo, UNLOCK);//imprime quem pegou o garfo
	pthread_mutex_lock(&philo->table->forks[philo->right_fork]);//pega o garfo da direita
	print_philo("has taken a fork", philo, UNLOCK);
	pthread_mutex_lock(&philo->table->count_meal);
	print_philo("is eating", philo, UNLOCK);
	philo->last_ate = get_time();//atualiza o tempo que o filósofo comeu
	pthread_mutex_unlock(&philo->table->count_meal);
	time_check(philo->table->time_to_eat, philo->table);// Dorme pelo tempo necessário para comer
	philo->ate_times++;//atualiza a quantidade de vezes que o filósofo comeu
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
}

void	philo_dead(t_table *table, t_philo *philo)
{
	int	i;

	while(!table->max_philo_eat)
	{
		i = -1;
		while(i++ < table->count_philo && !table->stop_condition)
		{
			pthread_mutex_lock(&table->count_meal);
			if((int)(get_time() - philo[i].last_ate) >= table->time_to_die)
			{
				print_philo("died", &philo[i], LOCK);//
				table->stop_condition = 1;
			}
			pthread_mutex_unlock(&table->count_meal);
		}
		if(table->stop_condition)
			break;
		i= 0;
		while(table->max_philo_eat && i < table->count_philo && philo[i].ate_times >= table->max_philo_eat)
			i++;
		table->max_ate = (i == table->count_philo);
	}
}

