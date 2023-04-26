/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:26:41 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 19:22:34 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void get_time(t_root *root)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    root->t_time = current_time.tv_sec * 1000;
}