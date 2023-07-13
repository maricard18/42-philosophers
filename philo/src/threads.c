/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:58:20 by maricard          #+#    #+#             */
/*   Updated: 2023/07/13 10:20:38 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// philospohers supervisor
int	supervisor(t_root *root)
{
	int	i;
	int	k;

	k = 0;
	while (k < root->n_philos)
	{
		i = 0;
		while (i < root->n_philos)
		{
			pthread_mutex_lock(&root->eat);
			if (root->philos[i].n_eat != root->n_philos_must_eat)
			{
				pthread_mutex_lock(&root->die);
				check_death_time(&root->philos[i]);
				pthread_mutex_unlock(&root->die);
			}
			else
				k++;
			pthread_mutex_unlock(&root->eat);
			if (root->n_philos_die)
				return (0);
			i++;
		}
	}
	return (0);
}

// routine function for main thread
void	*start_dinner(void *arg)
{
	t_philos		*ph;

	ph = arg;
	while (1)
	{
		check_for_forks(ph);
		if (ph->n_eat == ph->root->n_philos_must_eat)
		{
			pthread_mutex_lock(&ph->root->eat);
			ph->root->n_philos_ate++;
			pthread_mutex_unlock(&ph->root->eat);
			return (0);
		}
		pthread_mutex_lock(&ph->root->die);
		if (ph->root->n_philos_die)
		{
			pthread_mutex_unlock(&ph->root->die);
			return (0);
		}
		pthread_mutex_unlock(&ph->root->die);
		start_sleeping(ph);
		usleep(((ph->root->t_die - (ph->root->t_eat + ph->root->t_sleep)) / 2));
		start_thinking(ph);
	}
	return (0);
}

// start threads
void	start_threads(t_root *root)
{
	int	i;

	i = 0;
	root->philos = malloc(sizeof(t_philos) * root->n_philos);
	give_value_to_threads(root);
	root->start_time = get_time();
	mutexes_init(root);
	while (i < root->n_philos)
	{
		root->philos[i].index = i + 1;
		pthread_create(&root->philos[i].philo, NULL, &start_dinner,
			&root->philos[i]);
		i++;
	}
	supervisor(root);
	i = 0;
	while (i < root->n_philos)
	{
		pthread_join(root->philos[i].philo, NULL);
		i++;
	}
}
