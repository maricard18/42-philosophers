/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:58:20 by maricard          #+#    #+#             */
/*   Updated: 2023/04/25 17:20:24 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void*	start_dinner(void* args)
{	
	int	i;
	
	i = *(int*)args;
	printf("Number of forks: %d\n", i);
	return (0);
}

void	start_threads(t_root *root)
{
	int i;

	i = 0;
	root->t.philos = malloc(sizeof(pthread_t) * root->n_philos);
	pthread_mutex_init(&root->t.forks, NULL);
	while (i < root->n_philos)
	{
		pthread_create(&root->t.philos[i], NULL, &start_dinner, &root->n_forks);
		i++;
	}
	i = 0;
	while (i < root->n_philos)
	{
		pthread_join(root->t.philos[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&root->t.forks);
}