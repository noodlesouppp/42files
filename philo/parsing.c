/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 02:15:43 by yousong           #+#    #+#             */
/*   Updated: 2025/03/09 08:52:39 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_input(t_table *table, char **argv)
{
	table->num_of_philo = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1000;
	table->time_to_eat = ft_atol(argv[3]) * 1000;
	table->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (argv[5])
		table->nbr_limit_meals = ft_atol(argv[5]);
	else
		table->nbr_limit_meals = -1;
	if (table-> num_of_philo < 0 || table->time_to_die < 0
		|| table->time_to_eat < 0 || table->time_to_sleep < 0
		|| table->nbr_limit_meals < -1)
		return (FALSE);
	return (0);
}
