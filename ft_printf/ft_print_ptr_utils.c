/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:24:29 by yousong           #+#    #+#             */
/*   Updated: 2024/01/17 21:24:41 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
//#include "ft_printf.h"

int	ft_printptr(unsigned long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_hexptr(ptr);
		len += ft_ptrlen(ptr);
	}
	return (len);
}

void	ft_hexptr(unsigned long ptr)
{
	if (ptr >= 16)
	{
		ft_hexptr(ptr / 16);
		ft_hexptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_ptrlen(unsigned long ptr)
{
	int	len;

	len = 0;
	while (ptr)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}
