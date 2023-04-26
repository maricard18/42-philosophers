/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:58:20 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 23:56:36 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*start_dinner(void *arg)
{
	t_philos	*philos;

	philos = arg;
	while (philos->n_eat != philos->root->n_philos_must_eat
		|| philos->died == 0)
	{
		check_for_forks(philos);
		start_sleeping(philos);
		start_thinking(philos);
		if (get_time() - philos->root->time > philos->root->t_die)
			philos->died = 1;
	}
	printf("\nEnd!\n");
	return (0);
}

void	start_threads(t_root *root)
{
	int	i;

	i = 0;
	root->philos = malloc(sizeof(t_philos) * root->n_philos);
	give_value_to_threads(root);
	root->time = get_time();
	while (i < root->n_philos)
	{
		root->philos[i].index = i + 1;
		pthread_create(&root->philos[i].philo, NULL, &start_dinner,
				&root->philos[i]);
		i++;
	}
	i = 0;
	while (i < root->n_philos)
	{
		pthread_join(root->philos[i].philo, NULL);
		i++;
	}
}
