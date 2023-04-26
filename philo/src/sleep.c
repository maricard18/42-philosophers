/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:55:01 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 19:23:13 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    start_sleeping(t_philos *philos)
{
    printf("Chegueeeeeee 3\n");
    print(philos->index, "is sleeping 💤", philos);
    usleep(philos->root->t_sleep * 1000);
}