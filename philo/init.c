/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:46:33 by yousong           #+#    #+#             */
/*   Updated: 2025/03/11 10:25:19 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_fork *forks, int pos)
{
	int	num_of_philo;

	num_of_philo = philo->table->num_of_philo;
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[(pos + 1) % num_of_philo];
		philo->second_fork = &forks[pos];
	}
	else
	{
		philo->first_fork = &forks[pos];
		philo->second_fork = &forks[(pos + 1) % num_of_philo];
	}
}

static int	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->num_of_philo)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->meal_count = 0;
		philo->last_meal = 0;
		philo->full = false;
		philo->table = table;
		if (mutex_handler(&philo->philo_mtx, INIT) == FALSE)
			return (FALSE);
		assign_forks(philo, table->forks, i);
	}
	return (0);
}

int	data_init(t_table *table)
{
	int	i;

	i = -1;
	table->end_sim = false;
	table->all_threads_ready = false;
	table->nbr_threads = 0;
	table->philos = malloc(sizeof(t_philo) * table->num_of_philo);
	if (!table->philos)
		return (FALSE);
	if (mutex_handler(&table->table_mtx, INIT) == FALSE)
		return (FALSE);
	if (mutex_handler(&table->print_mtx, INIT) == FALSE)
		return (FALSE);
	table->forks = malloc(sizeof(t_fork) * table->num_of_philo);
	if (!table->forks)
		return (FALSE);
	while (++i < table->num_of_philo)
	{
		if (mutex_handler(&table->forks[i].fork, INIT) == FALSE)
			return (FALSE);
		table->forks[i].fork_id = i;
	}
	if (philo_init(table) == FALSE)
		return (FALSE);
	return (0);
}
