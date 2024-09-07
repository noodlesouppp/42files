/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:14:54 by yousong           #+#    #+#             */
/*   Updated: 2024/09/07 00:38:25 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	write_bits(int sig)
{
	static char	temp = 0;
	static int	bit = 0;

	if (sig == SIGUSR1)
		temp |= 0;
	else if (sig == SIGUSR2)
		temp |= 1;
	if (bit < 7)
		temp <<= 1;
	bit++;
	if (bit == 8)
	{
		write(1, &temp, 1);
		temp = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Usage: ./server\n", 1);
		return (1);
	}
	ft_putstr_fd("PID: ", 1);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	signal(SIGUSR1, write_bits);
	signal(SIGUSR2, write_bits);
	while (1)
		pause();
	return (0);
}
