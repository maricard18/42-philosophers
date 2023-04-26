/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:16:15 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 23:57:00 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(long long time, int philo, char *str, t_philos *philos)
{
	pthread_mutex_t	mutex;

	pthread_mutex_lock(&mutex);
	printf("%lld %d %s\n", time, philo, str);
	philos->n_eat = 1;
	pthread_mutex_unlock(&mutex);
}
