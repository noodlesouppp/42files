/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalise_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:47:00 by yousong           #+#    #+#             */
/*   Updated: 2024/06/16 23:34:07 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			closest_match;

	while (b)
	{
		closest_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num
				&& current_a->num < closest_match)
			{
				closest_match = current_a->num;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_match == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}

void	min_on_top(t_stack_node **a)
{
	while ((*a)->num != find_min(*a)->num)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
