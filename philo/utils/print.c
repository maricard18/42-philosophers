/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:16:15 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 19:09:46 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(int philo, char *str, t_philos *philos)
{
	pthread_mutex_t	mutex;
	long long		time;

	time = current_time() - philos->root->start_time;
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	if (philos->root->key == true)
		printf("%lld %d %s\n", time, philo, str);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
}
