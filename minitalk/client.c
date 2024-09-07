/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:14:43 by yousong           #+#    #+#             */
/*   Updated: 2024/09/07 17:18:20 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_ack_received = 0;

static void	ft_signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
}

static void	ft_send_bit(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack_received = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while(!g_ack_received)
			usleep(50);
		bit++;
	}
}

static void	ft_send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_bit(pid, str[i]);
		i++;
	}
	ft_send_bit(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3 && argv[2][0] != '\0')
	{
		signal(SIGUSR1, ft_signal_handler);
		pid = ft_atoi(argv[1]);
		ft_send_str(pid, argv[2]);
	}
	else
		ft_putstr_fd("Usage: ./client [PID] [STRING]\n", 1);
	return (0);
}
