/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:33:18 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 11:34:19 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_for_forks(t_philos *philos)
{
	philos->t_last_meal = 0;
	pthread_mutex_lock(philos->left);
	print(current_time() - philos->root->start_time, philos->index, \
			"Has taken a fork 🍴", philos);
	pthread_mutex_lock(philos->right);
	print(current_time() - philos->root->start_time, philos->index, \
			"is eating 🍝", philos);
	usleep(philos->root->t_eat * 1000);
	philos->n_eat++;
	philos->t_last_meal = current_time() - philos->root->start_time;
	pthread_mutex_unlock(philos->left);
	pthread_mutex_unlock(philos->right);
}
