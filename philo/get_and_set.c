/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:22:57 by yousong           #+#    #+#             */
/*   Updated: 2025/03/10 02:10:29 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(t_mtx *mutex, bool *target, bool value)
{
	mutex_handler(mutex, LOCK);
	*target = value;
	mutex_handler(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *target)
{
	bool	value;

	mutex_handler(mutex, LOCK);
	value = *target;
	mutex_handler(mutex, UNLOCK);
	return (value);
}

void	set_long(t_mtx *mutex, long *target, long value)
{
	mutex_handler(mutex, LOCK);
	*target = value;
	mutex_handler(mutex, UNLOCK);
}

long	get_long(t_mtx *mutex, long *target)
{
	long	value;

	mutex_handler(mutex, LOCK);
	value = *target;
	mutex_handler(mutex, UNLOCK);
	return (value);
}

bool	simulation_fin(t_table *table)
{
	return (get_bool(&table->table_mtx, &table->end_sim));
}
