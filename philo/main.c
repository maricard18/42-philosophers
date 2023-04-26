/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:32:02 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 23:43:33 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	start_threads(&root);
	return (0);
}
