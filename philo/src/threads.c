/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:58:20 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 20:34:17 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_time(void *arg)
{
	t_root	*root;
	int	i;

	root = arg;
	while (root->n_philos_die == 0)
	{
		i = 0;
		while (i < root->n_philos)
		{
			check_death_time(&root->philos[i]);
			if (root->n_philos_die != 0)
				exit (0);
			i++;
		}
	}
	return (0);
}

void	*start_dinner(void *arg)
{
	t_philos	*philos;

	philos = arg;
	while (philos->died == 0 && philos->n_eat != philos->root->n_philos_must_eat)
	{
		check_for_forks(philos);
		start_sleeping(philos);
		start_thinking(philos);
	}
	return (0);
}

void	start_threads(t_root *root)
{
	pthread_t	temp;
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
	pthread_create(&temp, NULL, &check_time, root);
	pthread_join(temp, NULL);
	i = 0;
	while (i < root->n_philos)
	{
		pthread_join(root->philos[i].philo, NULL);
		i++;
	}
	printf("\nFINISH\n");
}
