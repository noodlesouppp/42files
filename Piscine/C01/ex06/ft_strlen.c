/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:18:41 by yousong           #+#    #+#             */
/*   Updated: 2023/06/14 21:37:01 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/

int	ft_strlen(char *str)
{
	int	length;

	length = strlen(str);
	return (length);
}

/*int	main(void)
{
	char	str[] = "Supercalifragilisticexpialidocious";
	int	length;

	length = ft_strlen(str);
	printf("%d\n", length);
	return (0);
}*/
