/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:59:52 by maricard          #+#    #+#             */
/*   Updated: 2023/04/25 10:36:17 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sin;
	int		num;

	i = 0;
	sin = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sin = sin * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
			num = num * 10 + (str[i] - '0');
			i++;
	}
	return (num * sin);
}
