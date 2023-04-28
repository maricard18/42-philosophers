/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:58:20 by maricard          #+#    #+#             */
/*   Updated: 2023/04/28 12:20:04 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Routine function for secondary thread
void	*check_time(void *arg)
{
	t_root	*root;
	int		i;

	root = arg;
	while (root->n_philos_die == 0 && root->n_philos_ate != root->n_philos)
	{
		i = 0;
		while (i < root->n_philos)
		{
			if (root->philos[i].n_eat != root->n_philos_must_eat)
			{
				check_death_time(&root->philos[i]);
			}
			if (root->n_philos_die != 0)
			{
				break ;
			}
			i++;
		}
	}
	return (0);
}

// Routine function for main thread
void	*start_dinner(void *arg)
{
	t_philos	*philos;

	philos = arg;
	while (philos->root->n_philos_die == 0
		&& philos->n_eat != philos->root->n_philos_must_eat)
	{
		if (philos->root->n_philos_die == 0)
		{
			check_for_forks(philos);
			if (philos->n_eat == philos->root->n_philos_must_eat)
			{
				philos->root->n_philos_ate++;
				return (0);
			}
		}
		else
			return (0);
		if (philos->root->n_philos_die == 0)
			start_sleeping(philos);
		else
			return (0);
		if (philos->root->n_philos_die == 0)
			start_thinking(philos);
		else
			return (0);
	}
	return (0);
}

// Start threads
void	start_threads(t_root *root)
{
	pthread_t	temp;
	int			i;

	i = 0;
	root->philos = malloc(sizeof(t_philos) * root->n_philos);
	give_value_to_threads(root);
	root->start_time = current_time();
	pthread_create(&temp, NULL, &check_time, root);
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
	pthread_join(temp, NULL);
}
