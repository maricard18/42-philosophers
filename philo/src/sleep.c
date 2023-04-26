/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:55:01 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 23:57:28 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_sleeping(t_philos *philos)
{
	print(get_time() - philos->root->time, philos->index, "is sleeping 💤",
			philos);
	usleep(philos->root->t_sleep * 1000);
}