/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:55:01 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 16:28:30 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_sleeping(t_philos *philos)
{
	print(current_time() - philos->root->start_time, philos->index, \
			"is sleeping 💤");
	usleep(philos->root->t_sleep * 1000);
}
