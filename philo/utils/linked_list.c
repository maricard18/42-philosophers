/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:03:06 by maricard          #+#    #+#             */
/*   Updated: 2023/04/25 17:26:33 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_linked_list(t_root *root)
{
	int	i;
	t_fork *current;

	i = 0;
	current = &root->fork;
	while (i < root->n_forks)
	{
		current->next = malloc(sizeof(t_fork));
		i++;
		current = current->next;
		printf("List %d\n", i);
	}
	current->next = NULL;
}