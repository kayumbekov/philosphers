/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 00:55:12 by kbekov            #+#    #+#             */
/*   Updated: 2025/08/06 01:48:37 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	msg_log(t_philo *philo, int code)
{
	pthread_mutex_lock(&philo->table->m_log);
	if (end_simu(philo->table) && code != DIE)
		code = -1;
	if (code == EAT)
		printf("%s%09lld %zu is eating%s\n", GREEN, get_time()
			- philo->table->start_time_simu, philo->rank, NC);
	else if (code == SLEEP)
		printf("%s%09lld %zu is sleeping%s\n", BLUE, get_time()
			- philo->table->start_time_simu, philo->rank, NC);
	else if (code == THINK)
		printf("%s%09lld %zu is thinking%s\n", YELLOW, get_time()
			- philo->table->start_time_simu, philo->rank, NC);
	else if (code == DIE)
		printf("%s%09lld %zu died%s\n", RED, get_time()
			- philo->table->start_time_simu, philo->rank, NC);
	else if (code == TAKE_FORK)
		printf("%s%09lld %zu has taken a fork%s\n", CYAN, get_time()
			- philo->table->start_time_simu, philo->rank, NC);
	else if (code == WAIT_FORK)
		printf("%s%09lld %zu is wating for fork%s\n", YELLOW, get_time()
			- philo->table->start_time_simu, philo->rank, NC);
	pthread_mutex_unlock(&philo->table->m_log);
}


int end_simu(t_table *table)
{
    int result;

    result = 0;
    pthread_mutex_lock(&table->m_dead);
    result = table->dead;
    pthread_mutex_unlock(&table->m_dead);
    return (result);
}

void    set_end_simu(t_table *table)
{   
    pthread_mutex_lock(&table->m_dead);
    table->dead = 1;
    pthread_mutex_unlock(&table->m_dead);
}

void    synch_start(long long time_start)
{
    while(get_time() < time_start)
    {
        continue ;
    }
}