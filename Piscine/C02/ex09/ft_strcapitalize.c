/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:13:34 by yousong           #+#    #+#             */
/*   Updated: 2023/06/21 13:06:20 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
#include <stdio.h>
#include <string.h>*/

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capitalize_next;

	i = 0;
	capitalize_next = 1;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (capitalize_next && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			else if (!capitalize_next && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			capitalize_next = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			capitalize_next = 0;
		else
			capitalize_next = 1;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	if (str[0] == '\0')
	{
		return (0);
	}
	else
	{
		printf("%s", ft_strcapitalize(str));
	}
	return (0);
}*/
