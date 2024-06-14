/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:22:08 by yousong           #+#    #+#             */
/*   Updated: 2024/06/11 22:44:54 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	small_sort(t_stack_node **a)
{
	t_stack_node	*first;

	first = find_max(*a);
	if (first == *a)
		ra(a, false);
	else if ((*a)->next == first)
		rra(a, false);
	if ((*a)->num > (*a)->next->num)
		sa(a, false);
}
