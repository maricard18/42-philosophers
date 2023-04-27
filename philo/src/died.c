/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:23:29 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 19:53:21 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    philo_died(t_philos *philos)
{
	long long	time;
	char		*str;

	str = "died 💀\n";
	time = current_time() - philos->root->start_time;
	printf("%lld %d %s\n", time, philos->index, str);
}