/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:33:18 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 17:12:29 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_for_forks(t_philos *philos)
{
	philos->t_last_meal = 0;
	pthread_mutex_lock(philos->left);
	print(current_time() - philos->root->start_time, philos->index, \
			"has taken a fork 🍴");
	while (pthread_mutex_lock(philos->left))
		check_death_time(philos);
	pthread_mutex_lock(philos->right);
	print(current_time() - philos->root->start_time, philos->index, \
			"is eating 🍝");
	philos->t_last_meal = current_time() - philos->root->start_time;
	usleep(philos->root->t_eat * 1000);
	philos->n_eat++;
	pthread_mutex_unlock(philos->left);
	pthread_mutex_unlock(philos->right);
}
