/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:31:31 by yousong           #+#    #+#             */
/*   Updated: 2025/03/10 08:56:42 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	incr_thread(t_mtx *mutex, long *target)
{
	mutex_handler(mutex, LOCK);
	(*target)++;
	mutex_handler(mutex, UNLOCK);
}

bool	all_threads_running(t_mtx *mutex, long *threads, long num_of_philo)
{
	bool	ret;

	ret = false;
	mutex_handler(mutex, LOCK);
	if (*threads == num_of_philo)
		ret = true;
	mutex_handler(mutex, UNLOCK);
	return (ret);
}

long	get_time(t_time_type type)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (type == SECOND)
		return (tv.tv_sec + (tv.tv_usec / 1000000));
	else if (type == MILLISECOND)
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	else if (type == MICROSECOND)
		return ((tv.tv_sec * 1000000) + tv.tv_usec);
	return (0);
}

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mtx, &table->all_threads_ready))
		;
}
