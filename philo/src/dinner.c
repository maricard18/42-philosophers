/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 23:01:37 by maricard          #+#    #+#             */
/*   Updated: 2023/04/29 16:43:08 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// kill philosopher
void	philo_died(t_philos *philos)
{
	long long	time;
	char		*str;

	str = "died";
	time = get_time() - philos->root->start_time;
	printf(""BLUE"%lld  "GREEN"%d  "RED"%s\n", \
		time, philos->index, str);
}

// philosopher thinking function
void	start_thinking(t_philos *philos)
{
	print(philos->index, "is thinking", philos, THINK);
}

// philosopher sleeping function
void	start_sleeping(t_philos *philos)
{
	pthread_mutex_t	mutex;

	print(philos->index, "is sleeping", philos, SLEEP);
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	usleep(philos->root->t_sleep * 1000);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
}

// checking if there is forks available
void	check_for_forks(t_philos *philos)
{
	pthread_mutex_lock(philos->left);
	print(philos->index, "has taken a fork", philos, FORK);
	if (philos->root->n_philos == 1)
	{
		usleep(philos->root->t_die * 1000);
		pthread_mutex_unlock(philos->left);
		return ;
	}
	pthread_mutex_lock(philos->right);
	print(philos->index, "has taken a fork", philos, FORK);
	print(philos->index, "is eating", philos, EAT);
	pthread_mutex_lock(&philos->root->time);
	philos->t_last_meal = get_time() - philos->root->start_time;
	pthread_mutex_unlock(&philos->root->time);
	usleep(philos->root->t_eat * 1000);
	pthread_mutex_lock(&philos->root->eat);
	philos->n_eat++;
	pthread_mutex_unlock(&philos->root->eat);
	pthread_mutex_unlock(philos->left);
	pthread_mutex_unlock(philos->right);
}
