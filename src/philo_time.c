/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 00:55:10 by kbekov            #+#    #+#             */
/*   Updated: 2025/08/06 02:17:22 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void ft_wait(long long time_to_wait, t_table *table)
{
    long long   time;
    
    time = get_time() +  time_to_wait;
    while (!end_simu(table) && get_time() < time)
        usleep(500);
}

/*
    for getting current time in ms
*/

// long long get_time(void)
// {
//     struct timeval  current_time;
    
//     gettimeofday(&current_time, NULL);
//     return ((long long) (current_time.tv_sec * 1000LL) + (current_time.tv_use
//          / 1000)); 


// }

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((long long)(current_time.tv_sec * 1000LL) + (current_time.tv_usec
			/ 1000));
}