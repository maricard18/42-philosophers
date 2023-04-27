/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:03:44 by maricard          #+#    #+#             */
/*   Updated: 2023/04/27 21:13:46 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    clean_all(t_root *root)
{
    int i;

    i = 0;
    while (i < root->n_philos)
    {
        pthread_mutex_destroy(&root->forks[i]);
		i++;
    }
    free(root->forks);
    free(root->philos);
}