/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:26:41 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 21:19:12 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long   get_time()
{
    int i;
    
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    i = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    return (i);
}
