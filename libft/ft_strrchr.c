/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:20:04 by yousong           #+#    #+#             */
/*   Updated: 2023/11/06 17:29:06 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = strlen(str);
	if (c == '\0')
		return ((char *)&str[i]);
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	str[20] = "LLLWLLLLLWLLLWLL";

	printf("%s\n", ft_strrchr(str, 0));
	return (0);
}*/
