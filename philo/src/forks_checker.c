/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:33:18 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 19:38:41 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_for_forks(t_philos *philos)
{
	pthread_mutex_lock(philos->left);
	print(philos->index, "Has taken a fork 🍴", philos);
	pthread_mutex_lock(philos->right);
	print(philos->index, "is eating 🍝", philos);
	sleep(1);
//	printf("chegueeeee 1\n");
//	usleep(philos->root->t_eat * 1000);
//	printf("chegueeeee 2\n");
	pthread_mutex_unlock(philos->left);
	pthread_mutex_unlock(philos->right);
	printf("Philo %d finished eating\n", philos->index);
//	start_sleeping(philos);
//	start_thinking(philos);
}
