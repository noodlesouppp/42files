/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:33:01 by yousong           #+#    #+#             */
/*   Updated: 2024/06/14 05:08:18 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

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

/* Sorting */
void			small_sort(t_stack_node **a);
void			big_sort(t_stack_node **a, t_stack_node **b);

/* Stack */
t_stack_node	*get_cheapest(t_stack_node *a);
void			set_cheapest(t_stack_node *a);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);

/* Initiation */
void			set_index(t_stack_node *node);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			init_stack_a(t_stack_node **a, char **argv);

/* Utils */
int				stack_size(t_stack_node *stack);
char			**split(char *s, char c);
void			min_on_top(t_stack_node **a);
void			equalise_stack(t_stack_node **stack, t_stack_node *node, char stack_specifier);
void			rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
bool			is_sorted(t_stack_node *stack);


/* Errors */
int				error_syntax(char *str);
int				is_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **a);
void			free_errors(t_stack_node **a);

#endif
