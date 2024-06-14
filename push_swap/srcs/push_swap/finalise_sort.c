/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalise_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:47:00 by yousong           #+#    #+#             */
/*   Updated: 2024/06/14 05:04:55 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			closest_match;

	while(b)
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
			target_node = find_min(a);
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

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->num != find_min(*a)->num)
	{
		if (find_min(*a)->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}