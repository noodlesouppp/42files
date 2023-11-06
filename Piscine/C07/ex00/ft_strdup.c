/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:09:57 by yousong           #+#    #+#             */
/*   Updated: 2023/06/28 20:44:59 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*#include <string.h>
#include <stdio.h>*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		j;

	j = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (new == NULL)
		return (NULL);
	while (src[j])
	{
		new[j] = src[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

/*int	main(void)
{
	printf("%s\n", ft_strdup("print me PLEASE"));
	printf("%s\n", strdup("hope this works"));
	return (0);
}*/
