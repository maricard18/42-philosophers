/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:16:15 by maricard          #+#    #+#             */
/*   Updated: 2023/05/08 11:38:59 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// print function
void	print(int philo, char *str, t_philos *philos, int sms)
{
	long long		time;

	time = get_time() - philos->root->start_time;
	pthread_mutex_lock(&philos->root->die);
	if (philos->root->key == true)
	{
		if (sms == EAT)
			printf(""BLUE"%lld  "GREEN"%d  "YELLOW"%s\n", time, philo, str);
		if (sms == FORK)
			printf(""BLUE"%lld  "GREEN"%d  "GREY"%s\n", time, philo, str);
		if (sms == SLEEP)
			printf(""BLUE"%lld  "GREEN"%d  "CYAN"%s\n", time, philo, str);
		if (sms == THINK)
			printf(""BLUE"%lld  "GREEN"%d  "PURPLE"%s\n", time, philo, str);
	}
	pthread_mutex_unlock(&philos->root->die);
}
