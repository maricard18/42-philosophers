/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:57:43 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 21:33:54 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    start_thinking(t_philos *philos)
{
    print(get_time() - philos->root->time, philos->index, \
            "is thinking 💭", philos);
}