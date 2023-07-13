/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:26:41 by maricard          #+#    #+#             */
/*   Updated: 2023/05/08 15:25:40 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// check if the philosper died
void	check_death_time(t_philos *philos)
{
	pthread_mutex_lock(&philos->root->time);
	if (current_time(philos->root) - philos->t_last_meal \
			>= philos->root->t_die)
	{
		philos->root->key = false;
		philos->died = 1;
		philos->root->n_philos_die = 1;
		philo_died(philos);
	}
	pthread_mutex_unlock(&philos->root->time);
}

// get the current time
long long	current_time(t_root *root)
{
	long long		current_time;

	current_time = get_time() - root->start_time;
	return (current_time);
}

// get machine time
long long	get_time(void)
{
	long long		i;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	i = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (i);
}
