/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:14:43 by yousong           #+#    #+#             */
/*   Updated: 2024/09/07 21:45:32 by yousong          ###   ########.fr       */
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
	int	counter;

	bit = 0;
	while (bit < 8)
	{
		g_ack_received = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		counter = 0;
		while (!g_ack_received)
		{
			usleep(42);
			counter++;
			if (counter > 10000)
			{
				ft_putstr_fd("Error: No signal received!\n", 1);
				exit(1);
			}
		}
		bit++;
	}
}

void	ft_send_str(int pid, char *str)
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
	int	server_pid;

	if (argc == 3 && argv[2][0] != '\0')
	{
		signal(SIGUSR1, ft_signal_handler);
		server_pid = ft_atoi(argv[1]);
		if (ft_strlen(argv[1]) < 1 || server_pid == 0)
		{
			ft_putstr_fd("Invalid PID\n", 1);
			return (1);
		}
		while (*(argv[1]))
		{
			if (!ft_isdigit(*(argv[1])))
			{
				ft_putstr_fd("PID must be all numbers!\n", 1);
				return (1);
			}
			argv[1]++;
		}
		ft_send_str(server_pid, argv[2]);
	}
	else
		ft_putstr_fd("Usage: ./client [PID] [STRING]\n", 1);
	return (0);
}
