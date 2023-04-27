/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:58:20 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 12:25:56 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*start_dinner(void *arg)
{
	t_philos	*philos;

	philos = arg;
	while (philos->died == 0)
	{
		check_for_forks(philos);
		start_sleeping(philos);
		tests(philos);
		if ((current_time() - philos->root->start_time) > philos->root->t_die)
		{
			philo_died(philos);
			break ;
		}
		start_thinking(philos);
		if ((current_time() - philos->root->start_time) > philos->root->t_die)
		{
			philo_died(philos);
			break ;
		}
	}
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
}
