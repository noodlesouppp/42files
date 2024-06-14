/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 22:59:36 by yousong           #+#    #+#             */
/*   Updated: 2024/06/12 04:11:34 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack_node **top_node)
{
	t_stack_node	*last_node;

	if (!top_node || !*top_node || !(*top_node)->next)
		return ;
	last_node = find_last(*top_node);
	last_node->next = *top_node;
	(*top_node)->prev = last_node;
	*top_node = (*top_node)->next;
	(*top_node)->prev->next = NULL;
	(*top_node)->prev = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		write(1, "rr\n", 3);
}
