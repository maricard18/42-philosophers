/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:33:18 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 21:45:54 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_for_forks(t_philos *philos)
{
		pthread_mutex_lock(philos->left);
		print(get_time() - philos->root->time, philos->index, \
				"Has taken a fork 🍴", philos);
		pthread_mutex_lock(philos->right);
		print(get_time() - philos->root->time, philos->index, \
				"is eating 🍝", philos);
		usleep(philos->root->t_eat * 1000);
		philos->n_eat++;
		pthread_mutex_unlock(philos->left);
		pthread_mutex_unlock(philos->right);
}
