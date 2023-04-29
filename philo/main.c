/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:32:02 by maricard          #+#    #+#             */
/*   Updated: 2023/04/29 15:46:00 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// main function
int	main(int argc, char **argv)
{
	t_root	root;

	ft_bzero(&root, sizeof(t_root));
	if (argc < 5 || argc > 6)
	{
		printf("Program must receive at least 4 arguments to start\n");
		return (0);
	}
	init_args(&root, argv);
	if (root.n_philos == 0 || root.n_philos_must_eat == 0)
	{
		printf("<philos> / <meals> must be greater than 0\n");
		return (0);
	}
	start_threads(&root);
	clean_all(&root);
	return (0);
}
