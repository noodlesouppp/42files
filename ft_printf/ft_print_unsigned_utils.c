/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:24:57 by yousong           #+#    #+#             */
/*   Updated: 2024/01/17 21:25:05 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	int		length;
	char	*value;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		value = ft_uitoa(n);
		length += ft_printstr(value);
		free(value);
	}
	return (length);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n)
	{
		num[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_num_len(unsigned int n)
{
	int	num_length;

	num_length = 0;
	while (n)
	{
		num_length++;
		n = n / 10;
	}
	return (num_length);
}
