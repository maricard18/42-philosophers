/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:26:41 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 19:53:08 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_death_time(t_philos *philos)
{
	time_until_death(philos);
    if (philos->t_until_dead <= 0)
	{	
		philos->root->key = false;
		philos->died = 1;
		philos->root->n_philos_die = 1;
		philo_died(philos);
	}
	return (0);
}

void	time_until_death(t_philos *philos)
{
	philos->t_until_dead = philos->root->t_die - \
		((current_time() - philos->root->start_time) \
			- philos->t_last_meal);
}

long long	current_time(void)
{
	long long		i;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	i = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (i);
}
