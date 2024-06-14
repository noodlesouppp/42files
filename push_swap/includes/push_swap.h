/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:33:01 by yousong           #+#    #+#             */
/*   Updated: 2024/06/05 18:15:30 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack_node
{
	int					num;
	int					index;
	int					cost;
	bool				above_median;
	bool				is_cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}				t_stack_node;

/* Commands */
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **a, t_stack_node **b, bool print);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);

#endif