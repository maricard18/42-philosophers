/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 23:01:37 by maricard          #+#    #+#             */
/*   Updated: 2023/04/28 12:44:51 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Philosopher died
void	philo_died(t_philos *philos)
{
	long long	time;
	char		*str;

	str = "died 💀";
	time = current_time() - philos->root->start_time;
	printf("%lld %d %s\n", time, philos->index, str);
}

// Philosopher thinking function
void	start_thinking(t_philos *philos)
{
	print(philos->index, "is thinking 💭", philos);
}

// Philosopher sleeping function
void	start_sleeping(t_philos *philos)
{
	pthread_mutex_t mutex;

	print(philos->index, "is sleeping 💤", philos);
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	usleep(philos->root->t_sleep * 1000);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
}

// Checking if there is forks available
void	check_for_forks(t_philos *philos)
{
	pthread_mutex_lock(philos->left);
	print(philos->index, "has taken a fork 🍴", philos);
	if (philos->root->n_philos == 1)
	{
		usleep(philos->root->t_die * 1000);
		return ;
	}
	pthread_mutex_lock(philos->right);
	print(philos->index, "is eating 🍝", philos);
	philos->t_last_meal = current_time() - philos->root->start_time;
	usleep(philos->root->t_eat * 1000);
	philos->n_eat++;
	pthread_mutex_unlock(philos->left);
	pthread_mutex_unlock(philos->right);
}
