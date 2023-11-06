/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:29:23 by yousong           #+#    #+#             */
/*   Updated: 2023/06/27 16:12:44 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb > 0)
		return (nb * (ft_recursive_factorial(nb - 1)));
	return (0);
}

/*int	main(void)
{
	printf("%d", ft_recursive_factorial(4));
	return (0);
}*/
