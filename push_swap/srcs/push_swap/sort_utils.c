/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 03:08:20 by yousong           #+#    #+#             */
/*   Updated: 2024/06/14 03:42:56 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	equalise_stack(t_stack_node **stack, t_stack_node *node, char stack_specifier)
{
	while(*stack != node)
	{
		if (stack_specifier == 'a')
		{
			if (node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_specifier == 'b')
		{
			if (node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rr(a, b, false);
	set_index(*a);
	set_index(*b);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rrr(a, b, false);
	set_index(*a);
	set_index(*b);
}