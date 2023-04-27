/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:57:43 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 16:28:36 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_thinking(t_philos *philos)
{
	print(current_time() - philos->root->start_time, philos->index, \
			"is thinking 💭");
}
