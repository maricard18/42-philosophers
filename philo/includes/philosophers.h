/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:31:51 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 19:11:11 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4
# define FORK 5

typedef struct s_philos
{
	int				index;
	int				n_eat;
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
	long long		t_time;
	int				n_plates;
	int				n_philos;
	int				n_forks;
	int				n_philos_eat;
	int				n_philos_sleep;
	int				n_philos_die;
	int				n_philos_think;
	int				th_index;
	t_philos		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex;
}					t_root;

// Functions
// Utils
void				ft_bzero(void *s, size_t n);
void				init_args(t_root *root, char **argv);
int					ft_atoi(const char *str);
void				print(int philo, char *str, t_philos *philos);
void				tests(t_root *root);
void				get_time(t_root *root);

// src
void				start_threads(t_root *root);
void				check_for_forks(t_philos *philos);
void				give_value_to_threads(t_root *root);
void				start_sleeping(t_philos *philos);
void				start_thinking(t_philos *philos);

#endif