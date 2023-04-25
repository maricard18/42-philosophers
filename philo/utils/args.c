/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:31:40 by maricard          #+#    #+#             */
/*   Updated: 2023/04/25 10:40:53 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    init_args(t_root *root, char **argv)
{
	root->n_philos = ft_atoi(argv[1]);
	root->n_forks = root->n_philos;
	root->t_die = ft_atoi(argv[2]);
	root->t_eat = ft_atoi(argv[3]);
	root->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		root->n_philos_eat = ft_atoi(argv[5]);
}