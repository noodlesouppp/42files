/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 06:46:36 by yousong           #+#    #+#             */
/*   Updated: 2025/03/10 08:53:11 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	desync_philo(t_philo *philo)
{
	if (philo->table->num_of_philo % 2 == 1)
	{
		if (philo->id % 2 == 0)
			usleep(30000);
	}
}

static void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mtx, &philo->last_meal, get_time(MILLISECOND));
	incr_thread(&philo->table->table_mtx, &philo->table->nbr_threads);
	print_status(philo, TAKE_FIRST_FORK);
	while (!simulation_fin(philo->table))
		usleep(200);
	return (NULL);
}

void	*start_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mtx, &philo->last_meal, get_time(MILLISECOND));
	incr_thread(&philo->table->table_mtx, &philo->table->nbr_threads);
	while (!simulation_fin(philo->table))
	{
		if (philo->full)
			break ;
		eating(philo);
		sleeping(philo);
		thinking(philo, false);
		desync_philo(philo);
	}
	return (NULL);
}

void	simulation(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->num_of_philo == 1)
		thread_handler(&table->philos[0].thread_id, one_philo,
			&table->philos[0], CREATE);
	else
	{
		while (++i < table->num_of_philo)
			thread_handler(&table->philos[i].thread_id, start_sim,
				&table->philos[i], CREATE);
	}
	thread_handler(&table->monitor, monitor_dinner, table, CREATE);
	table->start_sim = get_time(MILLISECOND);
	set_bool(&table->table_mtx, &table->all_threads_ready, true);
	i = -1;
	while (++i < table->num_of_philo)
		thread_handler(&table->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&table->table_mtx, &table->end_sim, true);
	thread_handler(&table->monitor, NULL, NULL, JOIN);
}
