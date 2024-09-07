/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:14:43 by yousong           #+#    #+#             */
/*   Updated: 2024/09/07 03:07:26 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [message]\n", 1);
		return (1);
    }
	
	return (0);
}