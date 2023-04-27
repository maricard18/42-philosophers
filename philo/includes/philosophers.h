/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:31:51 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 19:15:34 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4
# define FORK 5

typedef struct s_philos
{
	int				index;
	int				n_eat;
	int				died;
	long long		t_last_meal;
	long long		t_until_dead;
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
	long long		eat_time;
	bool			key;
	int				n_plates;
	int				n_philos;
	int				n_forks;
	int				n_philos_ate;
	int				n_philos_must_eat;
	int				n_philos_die;
	int				th_index;
	t_philos		*philos;
	pthread_mutex_t	*forks;
}					t_root;

// Functions
// Utils
void				ft_bzero(void *s, size_t n);
void				init_args(t_root *root, char **argv);
int					ft_atoi(const char *str);
void				print(int philo, char *str, t_philos *philos);
void				tests(t_philos *philos);

// Time
long long			current_time(void);
void				time_until_death(t_philos *philos);
int 				check_death_time(t_philos *philos);

// src
void				start_threads(t_root *root);
void				check_for_forks(t_philos *philos);
void				give_value_to_threads(t_root *root);
void				start_sleeping(t_philos *philos);
void				start_thinking(t_philos *philos);
void				philo_died(t_philos *philos);

#endif