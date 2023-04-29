/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:18:23 by maricard          #+#    #+#             */
/*   Updated: 2023/04/29 18:54:32 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// usleep function
void ft_sleep(t_root *root, int time)
{
	long long		actual_time;

	actual_time = current_time(root);
	while (current_time(root) <= actual_time + time)
	{
		
	}
}
