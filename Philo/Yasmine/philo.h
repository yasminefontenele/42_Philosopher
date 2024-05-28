/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:40:40 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/26 18:00:40 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stddef.h>

# define RST    "\033[0m"      /* Reset to default color */
# define B      "\033[1;34m"   /* Bold Blue */


# define ERROR_USAGE "Please type: ./philo <n philosophers> <time to die>\
	<time to eat> <time to sleep> B[optional]RST<n times each philosopher must\
	eat>\n"

struct	t_table;

# define UNLOCK 1
# define LOCK 0

//representa cada filósofo
typedef struct s_philo
{
	int				ate_times;
	int				position;
	char			*position_numb;
	int				left_fork;
	int				right_fork;
	unsigned long	last_ate;
	pthread_t		philo_id;
	struct s_table	*table;//garante o acesso de cada um na "mesa"
}	t_philo;

typedef struct s_table
{
	int				count_philo;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				max_philo_eat;
	int				max_ate;
	unsigned long	time_start;
	int				stop_condition;
	pthread_mutex_t	*forks;
	pthread_mutex_t	count_meal;
	pthread_mutex_t	writing;//proteger o acesso as msgs na saída padrão
	t_philo			*philos;//array de filosofos
}	t_table;


//utils
unsigned long	get_time(void);
void 			time_check(unsigned long duration, t_table *table);
int				ft_checkint(const char *str_num);
int 			ft_error(char *msg_error);
//str_utils
char			*ft_itoa(int nbr);
int				ft_atoi(const char *str);
int				ft_strlen(char *str);
//threads
int 			init_threads(t_table *table);
//init.c
int				ft_init(t_table *table);
//philo.c
void 			print_philo(char *msg, t_philo *philo, int unlock);
void 			philo_eat(t_philo *philo);
void			philo_dead(t_table *table, t_philo *philo);

#endif

/*
 *		<pthread.h>:
 *      - pthread_create: Creates a new thread.
 *      - pthread_detach: Detaches a thread.
 *      - pthread_join: Joins with a terminated thread.
 *      - pthread_mutex_init: Initializes a mutex.
 *      - pthread_mutex_destroy: Destroys a mutex.
 *      - pthread_mutex_lock: Locks a mutex.
 *      - pthread_mutex_unlock: Unlocks a mutex.
 * */