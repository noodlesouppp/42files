/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:23:02 by yousong           #+#    #+#             */
/*   Updated: 2025/03/11 03:45:50 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, bool pre_sim)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (philo->full)
		return ;
	if (!pre_sim)
		print_status(philo, THINKING);
	if (philo->table->num_of_philo % 2 == 0)
		return ;
	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < t_eat)
		t_think = t_eat;
	usleep(t_think);
}

void	sleeping(t_philo *philo)
{
	if (philo->full)
		return ;
	if (!simulation_fin(philo->table))
		print_status(philo, SLEEPING);
	usleep(philo->table->time_to_sleep);
}

void	eating(t_philo *philo)
{
	mutex_handler(&philo->first_fork->fork, LOCK);
	print_status(philo, TAKE_FIRST_FORK);
	mutex_handler(&philo->second_fork->fork, LOCK);
	print_status(philo, TAKE_SECOND_FORK);
	set_long(&philo->philo_mtx, &philo->last_meal, get_time(MILLISECOND));
	philo->meal_count++;
	print_status(philo, EATING);
	usleep(philo->table->time_to_eat);
	if (philo->table->nbr_limit_meals > 0
		&& philo->meal_count == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mtx, &philo->full, true);
	mutex_handler(&philo->first_fork->fork, UNLOCK);
	mutex_handler(&philo->second_fork->fork, UNLOCK);
}
