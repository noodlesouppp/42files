/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:21:06 by yousong           #+#    #+#             */
/*   Updated: 2024/06/12 04:11:10 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack_node **top_node)
{
	t_stack_node	*last_node;

	if (!top_node || !*top_node || !(*top_node)->next)
		return ;
	last_node = find_last(*top_node);
	last_node->prev->next = NULL;
	last_node->next = *top_node;
	last_node->prev = NULL;
	*top_node = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		write(1, "rrr\n", 4);
}
