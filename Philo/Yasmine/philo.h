/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:40:40 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/24 19:09:49 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifdef PHILO_H
# define PHILO_H

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
	unsigned long	time_start;
	int				stop_condition;
	pthread_mutex_t	*forks;
	pthread_mutex_t	count_meal;
	pthread_mutex_t	writing;//proteger o acesso as msgs na saída padrão
	t_philo			*philos;//array de filosofos
}	t_table;

// typedef struct s_philo
// {
// 	int				ate_times;
// 	int				pos;
// 	char			*pos_str;
// 	int				ffork;
// 	int				sfork;
// 	unsigned long	last_ate;
// 	struct s_env	*env;
// 	pthread_t		thread_id;
// }				t_philo;

// typedef struct s_env
// {
// 	int				count;
// 	int				time_to_die;
// 	int				time_to_eat;
// 	int				time_to_sleep;
// 	int				eat_count_max;
// 	unsigned long	start_time;
// 	int				stop_condition;
// 	int				max_ate;
// 	t_philo			*philos;
// 	pthread_mutex_t	*forks;
// 	pthread_mutex_t	meal;
// 	pthread_mutex_t	writing;
// }				t_env;


void time_check(unsigned long duration, t_table *table);
unsigned long	get_time(void);
int	ft_strlen(char *str);
int	ft_checkint(const char *str_num);
int ft_error(char *msg_error);
char	*ft_itoa(int nbr);
int	ft_atoi(const char *str);
//init.c
int	ft_init(t_table *table);
//philo.c
void print_philo(char *msg, t_philo *philo, int unlock);



//
int		ft_atoi(const char *str);// convert a string to an integer
void	*philo(void *arg);// function for the philosopher thread
void	print_status(t_philo *philo, char *status);// print the status of the philosopher
void	ft_usleep(int time);// sleep for a certain amount of time
void	ft_sleep(t_philo *philo, int time);// sleep for a certain amount of time
void	ft_eat(t_philo *philo);// eat for a certain amount of time
void	ft_think(t_philo *philo);// think for a certain amount of time
void	ft_die(t_philo *philo);// die	
void	ft_take_forks(t_philo *philo);// take forks
void	ft_drop_forks(t_philo *philo);// drop forks
void	ft_init_philo(t_philo *philo, int id, int nb_philo, int time_to_die);// initialize the philosopher
void	ft_init_mutex(t_philo *philo);// initialize the mutex
void	ft_free(t_philo *philo);// free the memory

# endif