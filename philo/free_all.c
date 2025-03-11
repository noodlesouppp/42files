/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:14:16 by yousong           #+#    #+#             */
/*   Updated: 2025/03/11 14:04:32 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_table(t_table *table)
{
	t_philo	*philos;
	int		i;

	i = -1;
	while (++i < table->num_of_philo)
	{
		philos = table->philos + i;
		mutex_handler(&philos->philo_mtx, DESTROY);
	}
	i = -1;
	while (++i < table->num_of_philo)
	{
		mutex_handler(&table->forks[i], DESTROY);
	}
	mutex_handler(&table->print_mtx, DESTROY);
	mutex_handler(&table->table_mtx, DESTROY);
	free(table->forks);
	free(table->philos);
}
