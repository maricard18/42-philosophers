/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:00:26 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 16:21:19 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		root->philos[i].died = 0;
		root->philos[i].root = root;
		root->philos[i].n_eat = 0;
		root->philos[i].left = &root->forks[i];
		root->philos[i].right = &root->forks[i - 1];
		i++;
	}
	root->philos[0].left = &root->forks[root->n_philos - 1];
	root->philos[0].right = &root->forks[0];
}
