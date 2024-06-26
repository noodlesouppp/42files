/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 01:37:26 by yousong           #+#    #+#             */
/*   Updated: 2024/06/17 01:19:58 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_split(char **argv)
{
	int		i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

int	error_syntax(char *str)
{
	if (!(*str))
		return (1);
	if (!(*str == '-'
			|| *str == '+'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '-'
			|| *str == '+')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	is_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->num == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!a)
		return ;
	current = *a;
	while (current)
	{
		tmp = current->next;
		current->next = NULL;
		free(current);
		current = tmp;
	}
	*a = NULL;
}

void	free_errors(t_stack_node **a, char **argv, bool split_flag)
{
	free_stack(a);
	if (split_flag)
		free_split(argv);
	write(2, "Error\n", 6);
	exit(1);
}
