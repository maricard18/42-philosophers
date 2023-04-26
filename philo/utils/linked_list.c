/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:03:06 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 10:19:00 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_linked_list(t_root *root)
{
	int	i;
	t_fork *current;

	i = 0;
	current = &root->fork;
	root->fork.left_fork = 1;
	while (i < root->n_forks)
	{
		current->left_fork = 1;
		current->next = malloc(sizeof(t_fork));
		current = current->next;
		i++;
	}
	current->next = NULL;
}