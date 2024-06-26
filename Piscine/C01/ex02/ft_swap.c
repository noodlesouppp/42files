/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:48:02 by yousong           #+#    #+#             */
/*   Updated: 2023/06/14 16:04:46 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_swap(int *a, int *b)
{
	int	empty;

	empty = *a;
	*a = *b;
	*b = empty;
}

/*int	main(void)
{
	int	a;
	int	b;

	a = 69;
	b = 420;
	ft_swap(&a, &b);
	printf("%d\n", a);
	printf("%d\n", b);
	return (0);
}*/
