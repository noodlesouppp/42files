/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:22:51 by yousong           #+#    #+#             */
/*   Updated: 2025/03/10 08:33:25 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, const char status)
{
	long	elapsed;

	if (philo->full)
		return ;
	mutex_handler(&philo->table->print_mtx, LOCK);
	elapsed = get_time(MILLISECOND) - philo->table->start_sim;
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
		&& !simulation_fin(philo->table))
		printf("%-6ld" " %d has taken a fork\n", elapsed, philo->id);
	else if (status == EATING && !simulation_fin(philo->table))
		printf("%-6ld" " %d is eating\n", elapsed, philo->id);
	else if (status == SLEEPING && !simulation_fin(philo->table))
		printf("%-6ld" " %d is sleeping\n", elapsed, philo->id);
	else if (status == THINKING && !simulation_fin(philo->table))
		printf("%-6ld" " %d is thinking\n", elapsed, philo->id);
	else if (status == DIED)
		printf("%-6ld" " %d died\n", elapsed, philo->id);
	mutex_handler(&philo->table->print_mtx, UNLOCK);
}
