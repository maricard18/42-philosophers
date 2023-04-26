/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:16:15 by maricard          #+#    #+#             */
/*   Updated: 2023/04/26 10:34:23 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    print_message(t_root *root, int sms)
{
    if (sms == 1)
        printf("<time> %d is eating 🍝\n", root->th_index + 1);
    else if (sms == 2)
        printf("<time> %d is sleeping 💤\n", root->th_index + 1);
    else if (sms == 3)
        printf("<time> %d is thinking 💭\n", root->th_index + 1);
    else if (sms == 4)
        printf("<time> %d died 💀\n", root->th_index + 1);
    else if (sms == 5)
        printf("<time> %d has taken a fork 🍴\n", root->th_index + 1);
}