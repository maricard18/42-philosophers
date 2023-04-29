/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:00:26 by maricard          #+#    #+#             */
/*   Updated: 2023/04/29 15:49:55 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// if a philosper is "odd"
void	odd_philo(t_root *root, int i)
{
	if (i + 1 == root->n_philos)
	{
		root->philos[i].t_last_meal = 0;
		root->philos[i].died = 0;
		root->philos[i].root = root;
		root->philos[i].n_eat = 0;
		root->philos[i].right = &root->forks[i];
		root->philos[i].left = &root->forks[0];
	}
	else
	{
		root->philos[i].t_last_meal = 0;
		root->philos[i].died = 0;
		root->philos[i].root = root;
		root->philos[i].n_eat = 0;
		root->philos[i].right = &root->forks[i];
		root->philos[i].left = &root->forks[i + 1];
	}
}

// if a philosper is "even"
void	even_philo(t_root *root, int i)
{
	if (i + 1 == root->n_philos)
	{
		root->philos[i].t_last_meal = 0;
		root->philos[i].died = 0;
		root->philos[i].root = root;
		root->philos[i].n_eat = 0;
		root->philos[i].right = &root->forks[0];
		root->philos[i].left = &root->forks[i];
	}
	else
	{
		root->philos[i].t_last_meal = 0;
		root->philos[i].died = 0;
		root->philos[i].root = root;
		root->philos[i].n_eat = 0;
		root->philos[i].right = &root->forks[i + 1];
		root->philos[i].left = &root->forks[i];
	}
}

// init external mutexes
void	mutexes_init(t_root *root)
{
	pthread_mutex_init(&root->die, NULL);
	pthread_mutex_init(&root->eat, NULL);
	pthread_mutex_init(&root->time, NULL);
}

// init fork mutexes and give them values
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
	i = 0;
	while (i < root->n_philos)
	{
		if (i % 2 == 0)
			odd_philo(root, i);
		else
			even_philo(root, i);
		i++;
	}
}
