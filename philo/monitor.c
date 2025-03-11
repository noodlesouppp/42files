/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:58:08 by yousong           #+#    #+#             */
/*   Updated: 2025/03/11 10:21:48 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static bool	is_dead(t_philo *philo)
{
	long	elapsed;
	long	death_timer;

	if (get_bool(&philo->philo_mtx, &philo->full))
		return (false);
	elapsed = get_time(MILLISECOND) - get_long(&philo->philo_mtx,
			&philo->last_meal);
	death_timer = philo->table->time_to_die / 1000;
	if (elapsed > death_timer)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data)
{
	int		i;
	t_table	*table;

	table = (t_table *)data;
	while (!all_threads_running(&table->table_mtx, &table->nbr_threads,
			table->num_of_philo))
		;
	while (!simulation_fin(table))
	{
		i = -1;
		while (++i < table->num_of_philo && !simulation_fin(table))
		{
			if (is_dead(table->philos + i))
			{
				print_status(table->philos + i, DIED);
				set_bool(&table->table_mtx, &table->end_sim, true);
			}
		}
	}
	return (NULL);
}
