/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:14:54 by yousong           #+#    #+#             */
/*   Updated: 2024/09/07 17:01:04 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	write_bits(int sig, siginfo_t *info, void *s)
{
	static unsigned char	temp = 0;
	static int				bit = 0;
	int						pid;

	(void)s;
	pid = info->si_pid;
	if (sig == SIGUSR2)
		temp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(temp, 1);
		if (temp == '\0')
			ft_putchar_fd('\n', 1);
		temp = 0;
		bit = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	pid_t				pid;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Usage: ./server\n", 1);
		return (1);
	}
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &write_bits;
	sigemptyset(&sig.sa_mask);
	ft_putstr_fd("PID: ", 1);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
