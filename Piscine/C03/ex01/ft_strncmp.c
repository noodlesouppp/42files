/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:00:22 by yousong           #+#    #+#             */
/*   Updated: 2023/06/21 16:25:58 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
#include <stdio.h>*/

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] == s2[i] && s1[i] && ((n - 1) > 0))
	{
		i++;
		n--;
	}
	return (s1[i] - s2[i]);
}

/*int	main(void)
{
	char	s1[] = "tweedledee";
	char	s2[] = "tweedledum";
	unsigned int	n = 9;

	printf("%d\n", ft_strncmp(s1, s2, n));
	return (0);
}*/
