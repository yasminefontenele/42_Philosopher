/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:40:40 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/29 09:55:38 by yasmine          ###   ########.fr       */
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

# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"

# define ERROR_USAGE "Please type: ./philo <n philosophers> <time to die> <time to eat> <time to sleep> <n times each philosopher must eat>\n"

# define INT_MAX 2147483647

# define TRUE 1
# define FALSE 0

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died 👻"


# define UNLOCK 1
# define LOCK 0

typedef struct s_args
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_times_eat;
}					t_args;

typedef struct s_fork
{
	int				left;
	int				right;
}					t_fork;


//representa cada filósofo
typedef struct s_philo
{
	int				philo_id;
	int				times_ate;
	long long 		time_to_die;
	t_fork			fork;
	pthread_t		thread;
}	t_philo;

typedef struct s_table
{
	int 			nbr_threads;
	int				dead_philo;//dead philo
	long long 		start_time;//t0
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;//write
	pthread_t		waiter;//rchestrator;
	t_args			args;
}	t_table;

int	philo_eat(t_table *table, int i);
int	philo_sleep(t_table *table, int i);
int	philo_think(t_table *table, int i);
int	philo_is_dead(t_table *table, int *i);
int	drop_forks(t_table *table, int i);

void	*routine(void *args);
int	routine_execute(t_table *table, int i);
void	*checker(void *args);
int	philo_print(t_table *table, int id, char *color, char *status);

int	create_threads(t_table *table);
int	join_threads(t_table *table);
int	destroy_threads(t_table *table);

long long	get_time(void);
long long	delta_time(long long time);
void	exec_action(long long time);

int	philo_atoi(char *str);
int	philo_strncmp(const char *s1, const char *s2, size_t n);
int	philo_strlen(const char *str);
void	philo_free(t_table *table);

int	create_forks(t_table *table);
void	unlock_forks(t_table *table);

int	just_one_philo(t_table *table);

int	create_philos(t_table *table);
void	fill_philo_struct(t_table *table, int i, int j);

int	error_handling(int ac, char **av, t_table *table);
int	init_input_struct(int ac, char **av, t_table *table);





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