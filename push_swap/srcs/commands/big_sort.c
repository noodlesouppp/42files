/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:04:23 by yousong           #+#    #+#             */
/*   Updated: 2024/06/14 04:01:30 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target->above_median))
		rev_rotate_both(a, b, cheapest);
	equalise_stack(a, cheapest, 'a');
	equalise_stack(b, cheapest->target, 'b');
	pb(a, b, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	equalise_stack(a, (*b)->target, 'a');
	pa(a, b, false);
}

t_stack_node	*get_cheapest(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->is_cheapest)
			return (a);
		a = a->next;
	}
	return (NULL);
}

void	big_sort(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_size(*a);
	if (len-- > 3 && !is_sorted(*a))
		pb(a, b, false);
	if (len-- > 3 && !is_sorted(*a))
		pb(a, b, false);
	while(len-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	small_sort(a);
	while(*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}