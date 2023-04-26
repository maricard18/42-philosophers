/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:00:26 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 10:40:10 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_for_forks(t_root *root)
{
    if (root->fork.left_fork == 1 ||
        root->fork.next->left_fork == 1)
    {
        pthread_mutex_lock(&root->t.mutex);
        print_message(root, FORK);
        root->fork.left_fork = 0;
        root->fork.next->left_fork = 0;
        pthread_mutex_unlock(&root->t.mutex);
    }
    return (0);
}