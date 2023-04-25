/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:31:51 by maricard          #+#    #+#             */
/*   Updated: 2023/04/25 10:53:52 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_root
{
    int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_plates;
	int n_philos;
    int n_forks;
	int n_philos_eat;
	int n_philos_sleep;
	int n_philos_die;
	int n_philos_think;
}   t_root;

// Functions
// Utils
void	ft_bzero(void *s, size_t n);
void	init_args(t_root *root, char **argv);
int		ft_atoi(const char *str);
void	tests(t_root *root);

#endif