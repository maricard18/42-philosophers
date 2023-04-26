/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:58:20 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 10:37:03 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void*	start_dinner(void* root)
{	
	check_for_forks(root);
	return (0);
}

void	start_threads(t_root *root)
{
	root->th_index = 0;
	root->t.philos = malloc(sizeof(pthread_t) * root->n_philos);
	pthread_mutex_init(&root->t.mutex, NULL);
	while (root->th_index < root->n_philos)
	{
		pthread_create(&root->t.philos[root->th_index], NULL, \
												&start_dinner, root);
		root->th_index++;
	}
	root->th_index = 0;
	while (root->th_index < root->n_philos)
	{
		pthread_join(root->t.philos[root->th_index], NULL);
		root->th_index++;
	}
	pthread_mutex_destroy(&root->t.mutex);
}
