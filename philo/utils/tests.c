/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:37:44 by maricard          #+#    #+#             */
/*   Updated: 2023/04/25 10:38:37 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	tests(t_root *root)
{
	printf("n_philos: %d\n", root->n_philos);
	printf("n_forks: %d\n", root->n_forks);
	printf("t_die: %d\n", root->t_die);
	printf("t_eat: %d\n", root->t_eat);
	printf("t_sleep: %d\n", root->t_sleep);
	if (root->n_philos_eat)
		printf("n_philos_eat: %d\n", root->n_philos_eat);
}