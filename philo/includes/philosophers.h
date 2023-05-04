/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:31:51 by maricard          #+#    #+#             */
/*   Updated: 2023/05/04 08:12:41 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EAT 0
# define SLEEP 1
# define THINK 2
# define FORK 3

# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define PURPLE "\033[0;35m"
# define GREY "\033[0;90m"

// Structs
typedef struct s_philos
{
	int				index;
	int				n_eat;
	int				died;
	long long		t_last_meal;
	pthread_t		philo;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct s_root	*root;
}					t_philos;

typedef struct s_root
{
	long long		t_die;
	long long		t_eat;
	long long		t_sleep;
	long long		start_time;
	bool			key;
	int				n_philos;
	int				n_forks;
	int				n_philos_ate;
	int				n_philos_must_eat;
	int				n_philos_die;
	t_philos		*philos;
	pthread_mutex_t	die;
	pthread_mutex_t	eat;
	pthread_mutex_t	time;
	pthread_mutex_t	*forks;
}					t_root;

// Functions
// Utils
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				init_args(t_root *root, char **argv);
void				init_args(t_root *root, char **argv);
void				print(int philo, char *str, t_philos *philos, int sms);
void				mutexes_init(t_root *root);
void				give_value_to_threads(t_root *root);
void				clean_all(t_root *root);

// Time
long long			get_time(void);
long long			current_time(t_root *root);
void				time_until_death(t_philos *philos);
void				check_death_time(t_philos *philos);

// src
void				start_threads(t_root *root);
void				check_for_forks(t_philos *philos);
void				start_sleeping(t_philos *philos);
void				start_thinking(t_philos *philos);
void				philo_died(t_philos *philos);

// Tests
void				tests(t_philos *philos);

#endif