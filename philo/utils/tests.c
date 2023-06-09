/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:37:44 by maricard          #+#    #+#             */
/*   Updated: 2023/04/29 15:47:27 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// tetst function
void	tests(t_philos *philos)
{
	printf("\nCurrent time: %lld\n", get_time() - philos->root->start_time);
	printf("Philo %d last meal: %lld\n", philos->index, philos->t_last_meal);
	printf("t_die: %lld\n", philos->root->t_die);
	printf("Time until philo %d is dead: %lld\n", philos->index, \
		philos->root->t_die - ((get_time() - philos->root->start_time) \
		- philos->t_last_meal));
	if (philos->root->n_philos_must_eat)
		printf("Number of dinners: %d\n", philos->root->n_philos_must_eat);
}
