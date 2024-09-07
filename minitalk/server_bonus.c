/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:03:54 by yousong           #+#    #+#             */
/*   Updated: 2024/09/07 20:27:19 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	write_bits(int sig, siginfo_t *info, void *s)
{
	static unsigned char	temp = 0;
	static int				bit_index = 0;
	int						pid;

	(void)s;
	pid = info->si_pid;
	if (sig == SIGUSR2)
		temp |= (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		ft_putchar_fd(temp, 1);
		if (temp == '\0')
			ft_putchar_fd('\n', 1);
		temp = 0;
		bit_index = 0;
		kill(pid, SIGUSR1);
		kill(pid, SIGUSR2);
	}
	else
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
