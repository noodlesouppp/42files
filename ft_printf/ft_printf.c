/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:22:49 by yousong           #+#    #+#             */
/*   Updated: 2024/01/17 21:23:20 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list ap, const char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_printchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_printstr(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_printptr(va_arg(ap, unsigned long long));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_printnbr(va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_printunsigned(va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_printhex(va_arg(ap, unsigned int), specifier);
	else if (specifier == '%')
		count += ft_printperc();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += ft_format(ap, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int	count;

	count = ft_printf("Hello %s\n", "there");
	ft_printf("The chars written are %d\n", count);
}
