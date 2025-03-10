/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:54:41 by yousong           #+#    #+#             */
/*   Updated: 2025/03/10 06:00:06 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		if (parse_input(&table, argv) == FALSE)
		{
			print_err("Invalid arguments!");
			return (1);
		}
		if (data_init(&table) == FALSE)
		{
			print_err("Failed to initialize data!");
			return (1);
		}
		simulation(&table);
		free_table(&table);
	}
	else
	{
		print_err("Invalid no. of arguments!");
		return (1);
	}
}
