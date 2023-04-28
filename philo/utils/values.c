/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:00:26 by maricard          #+#    #+#             */
/*   Updated: 2023/04/28 12:54:12 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	odd_philo(t_root *root, int i)
{
	root->philos[i].t_last_meal = 0;
	root->philos[i].died = 0;
	root->philos[i].root = root;
	root->philos[i].n_eat = 0;
	root->philos[i].left = &root->forks[i - 1];
	root->philos[i].right = &root->forks[i];
}

void	even_philo(t_root *root, int i)
{
	root->philos[i].t_last_meal = 0;
	root->philos[i].died = 0;
	root->philos[i].root = root;
	root->philos[i].n_eat = 0;
	root->philos[i].left = &root->forks[i];
	root->philos[i].right = &root->forks[i - 1];
}

void	give_value_to_threads(t_root *root)
{
	int	i;

	i = 0;
	root->forks = malloc(sizeof(pthread_mutex_t) * root->n_philos);
	while (i < root->n_philos)
	{
		pthread_mutex_init(&root->forks[i], NULL);
		i++;
	}
	i = 1;
	while (i < root->n_philos)
	{
		if (i % 2 == 0)
			odd_philo(root, i);
		else
			even_philo(root, i);
		i++;
	}
	root->philos[0].t_last_meal = 0;
	root->philos[0].died = 0;
	root->philos[0].root = root;
	root->philos[0].n_eat = 0;
	root->philos[0].left = &root->forks[0];
	root->philos[0].right = &root->forks[root->n_philos - 1];
}
