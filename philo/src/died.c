/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:23:29 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 11:51:02 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    philo_died(t_philos *philos)
{
    philos->died = 1;
	print(current_time() - philos->root->start_time, philos->index, \
			"died 💀", philos);
}