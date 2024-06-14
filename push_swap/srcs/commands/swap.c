/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:12:07 by yousong           #+#    #+#             */
/*   Updated: 2024/06/12 04:11:45 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack_node **top_node)
{
	if (!top_node || !*top_node || !(*top_node)->next)
		return ;
	(*top_node) = (*top_node)->next;
	(*top_node)->prev->prev = (*top_node);
	(*top_node)->prev->next = (*top_node)->next;
	if ((*top_node)->next)
		(*top_node)->next->prev = (*top_node)->prev;
	(*top_node)->next = (*top_node)->prev;
	(*top_node)->prev = NULL;
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		write(1, "ss\n", 3);
}
