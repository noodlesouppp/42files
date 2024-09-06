/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:14:54 by yousong           #+#    #+#             */
/*   Updated: 2024/09/06 19:09:47 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	write_bits(int sig)
{
	static char	temp;
	static int	bit;

	
}

int	main(void)
{
	int pid;

	ft_putstr_fd("PID: ", 1);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	signal(SIGUSR1, write_bits);
	signal(SIGUSR2, write_bits);
	while(1)
		pause();
	return (0);
}
