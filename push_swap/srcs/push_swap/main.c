/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:22:33 by yousong           #+#    #+#             */
/*   Updated: 2024/06/05 18:20:16 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!is_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, false);
		else if (stack_size(a) == 3)
			small_sort(&a);
		else
			big_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
