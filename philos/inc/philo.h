/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:44:36 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/29 13:45:01 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define NONE "\033[0m"

# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define EAT "is eating"
# define DIED "died"

typedef pthread_mutex_t	t_mutex;

typedef enum e_args
{
	PHILO_NUM = 1,
	DEATH_TIME = 2,
	EAT_TIME = 3,
	SLEEP_TIME = 4,
	MEAL_NUM = 5
}					t_args;

typedef struct s_time
{
	int				to_die;
	int				to_eat;
	int				to_sleep;
}					t_time;

typedef struct s_data
{
	int				philo_num;
	t_time			time;
	int				n_eat;
	int				philo_died;
	long long		timer;
	pthread_t		monitor;
	t_mutex			*mymutex;
	t_mutex			shared;
	t_mutex			tm;
	t_mutex			print;
}					t_data;

typedef struct s_fork
{
	int				left;
	int				right;
}					t_fork;

typedef struct s_philo
{
	int				phi_id;
	long long		t_die;
	int				n_eaten;
	t_fork			hand;
	pthread_t		th;
	t_data			*data;
}					t_philo;

/**
 * UTILS FUNCTIONS
 */
int					ft_error(char *message);
int					is_digit(char *str);
int					ft_atoi(const char *str);
/**
 * HELPER FUNCTIONS
 */
int					validator(int argc, char **argv);
int					validate_value(long val, t_args type);
/**
 * INIT FUNCTIONS
 */
int					init_data(t_data *data, char **argv, int argc);
void				init_philo(t_philo *phi, t_data *data);
int					mutex_init(t_data *data);
/**
 * ROUTINE FUNCTIONS
 */
void				*monitor(void *args);
void				*handle_philo(void *arg);
/**
 * MSG FUNCTIONS
 */
int					print_state(t_philo *phi, int id, char *color,
						char *status);
/**
 * TIME FUNCTIONS
 */
long long			get_time(void);
long long			time_diff(long long time);
void				time_sim(long long time);
/**
 * FREE FUNCTIONS
 */
void				free_all(t_data *data, t_philo *phi);
void				free_single(t_data *data, t_philo *phi);
/**
 * ACTION FUNCTIONS
 */
int					philo_eat(t_philo *phi);
int					philo_sleep(t_philo *phi);
int					philo_think(t_philo *phi);
int					is_dead(t_philo *phi, int *i);
void				drop_forks(t_philo *phi, int flag);
int					philo_sleep(t_philo *phi);
/**
 * THREAD FUNCTIONS
 */
int					handle_thread(t_philo *phi);

#endif