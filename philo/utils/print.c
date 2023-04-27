/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:16:15 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 16:27:54 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(long long time, int philo, char *str)
{
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	printf("%lld %d %s\n", time, philo, str);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
}
