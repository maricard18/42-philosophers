/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:58:20 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 17:09:48 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*start_dinner(void *arg)
{
	t_philos	*philos;

	philos = arg;
	while (philos->died == 0 && philos->n_eat != philos->root->n_philos_must_eat)
	{
		check_for_forks(philos);
		check_death_time(philos);
		start_sleeping(philos);
		check_death_time(philos);
		start_thinking(philos);
	}
	tests(philos);
	return (0);
}

void	start_threads(t_root *root)
{
	int	i;

	i = 0;
	root->philos = malloc(sizeof(t_philos) * root->n_philos);
	give_value_to_threads(root);
	root->start_time = current_time();
	while (i < root->n_philos)
	{
		root->philos[i].index = i + 1;
		pthread_create(&root->philos[i].philo, NULL, &start_dinner, \
						&root->philos[i]);
		i++;
	}
	i = 0;
	while (i < root->n_philos)
	{
		pthread_join(root->philos[i].philo, NULL);
		i++;
	}
	if (root->philos->n_eat == root->n_philos_must_eat)
		printf("\nCharlie all done brother, we made it!\n");
}
