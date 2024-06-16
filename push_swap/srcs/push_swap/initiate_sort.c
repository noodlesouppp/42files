/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:35:18 by yousong           #+#    #+#             */
/*   Updated: 2024/06/16 23:35:12 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_cheapest(t_stack_node *a)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!a)
		return ;
	cheapest_value = LONG_MAX;
	while (a)
	{
		if (a->cost < cheapest_value)
		{
			cheapest_value = a->cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	if (cheapest_node)
		cheapest_node->is_cheapest = true;
}

static void	calculate_cost(t_stack_node *a, t_stack_node *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_size(a);
	b_len = stack_size(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = a_len - a->index;
		if (a->target->above_median)
			a->cost += a->target->index;
		else
			a->cost += b_len - a->target->index;
		a = a->next;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			closest_match;

	while (a)
	{
		closest_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->num < a->num
				&& current_b->num > closest_match)
			{
				closest_match = current_b->num;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_match == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	set_index(t_stack_node *node)
{
	int	i;
	int	median;

	i = 0;
	if (!node)
		return ;
	median = stack_size(node) / 2;
	while (node)
	{
		node->index = i;
		if (i < median)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
		i++;
	}
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	calculate_cost(a, b);
	set_cheapest(a);
}
