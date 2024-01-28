/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:23:47 by yousong           #+#    #+#             */
/*   Updated: 2024/01/17 21:23:50 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
//#include "libft.h"

int	ft_print_hex(unsigned int num, const char specifier)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, specifier);
	return (ft_hex_len(num));
}

void	ft_put_hex(unsigned int num, const char specifier)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, specifier);
		ft_put_hex(num % 16, specifier);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (specifier == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (specifier == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_hex_len(unsigned int	num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}