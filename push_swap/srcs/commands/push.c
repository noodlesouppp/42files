/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:24:49 by yousong           #+#    #+#             */
/*   Updated: 2024/06/14 07:10:34 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack_node **d, t_stack_node **s)
{
	t_stack_node	*push_node;

	if (!*s)
		return ;
	push_node = *s;
	*s = (*s)->next;
	if (*s)
		(*s)->prev = NULL;
	push_node->prev = NULL;
	if (*d == NULL)
	{
		*d = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *d;
		push_node->next->prev = push_node;
		*d = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}
