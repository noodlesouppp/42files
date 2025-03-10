/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:56:29 by yousong           #+#    #+#             */
/*   Updated: 2025/03/09 22:35:04 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*nbr;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-' || (!is_digit(*str)))
		return (NULL);
	nbr = str;
	while (is_digit(*str++))
		len++;
	if (len > 10)
		return (NULL);
	return (nbr);
}

long	ft_atol(const char *str)
{
	long		num;
	const char	*nbr;

	num = 0;
	nbr = valid_input(str);
	if (nbr == NULL)
		return (FALSE);
	while (is_digit(*nbr))
		num = (num * 10) + (*nbr++ - '0');
	if (num > INT_MAX)
		return (FALSE);
	return (num);
}

void	print_err(const char *error)
{
	printf("%s\n", error);
}
