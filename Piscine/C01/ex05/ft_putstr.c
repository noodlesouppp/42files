/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:43:26 by yousong           #+#    #+#             */
/*   Updated: 2023/06/14 19:13:29 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
#include <string.h>*/

void	ft_putstr(char *str)
{
	write(1, str, strlen(str));
}

/*int	main(void)
{
	char	str[] = "Hello, C";

	ft_putstr(str);
	return (0);
}*/
