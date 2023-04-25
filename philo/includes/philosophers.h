/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:31:51 by maricard          #+#    #+#             */
/*   Updated: 2023/04/25 17:19:27 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_fork
{
	int				left_fork;
	struct s_fork	*next;
}   t_fork;

typedef struct s_thread
{
	pthread_t   	*philos;
	pthread_mutex_t	forks;
}   t_thread;

typedef struct s_root
{
    int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_plates;
	int			n_philos;
    int			n_forks;
	int			n_philos_eat;
	int			n_philos_sleep;
	int			n_philos_die;
	int			n_philos_think;
	t_thread	t;
	t_fork		fork;
}   t_root;

// Functions
// Utils
void	ft_bzero(void *s, size_t n);
void	init_args(t_root *root, char **argv);
int		ft_atoi(const char *str);
void	init_linked_list(t_root *root);
void	tests(t_root *root);

// src
void	start_threads(t_root *root);

#endif