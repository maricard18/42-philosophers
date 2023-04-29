/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:03:44 by maricard          #+#    #+#             */
/*   Updated: 2023/04/29 15:46:03 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// clean all the mutexes and free the memory
void	clean_all(t_root *root)
{
	int	i;

	i = 0;
	while (i < root->n_philos)
	{
		pthread_mutex_destroy(&root->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&root->die);
	pthread_mutex_destroy(&root->eat);
	pthread_mutex_destroy(&root->time);
	free(root->forks);
	free(root->philos);
}
