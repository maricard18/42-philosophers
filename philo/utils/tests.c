/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:37:44 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 23:56:57 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	tests(t_root *root)
{
	printf("n_philos: %d\n", root->n_philos);
	printf("n_forks: %d\n", root->n_forks);
	printf("t_die: %lld\n", root->t_die);
	printf("t_eat: %lld\n", root->t_eat);
	printf("t_sleep: %lld\n", root->t_sleep);
	if (root->n_philos_must_eat)
		printf("n_philos_eat: %d\n", root->n_philos_must_eat);
}
