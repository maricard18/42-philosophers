/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:16:15 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 18:46:37 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(int philo, char *str, t_philos *philos)
{
	pthread_mutex_t	mutex;
	
	pthread_mutex_lock(&mutex);
	printf("<time> %d %s\n", philo, str);
	philos->n_eat = 1;
	pthread_mutex_unlock(&mutex);
}
