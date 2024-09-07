/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:04:08 by yousong           #+#    #+#             */
/*   Updated: 2024/09/07 21:45:55 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

struct s_client_bonus	g_client_bonus = {0, 0};

static void	ft_signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_client_bonus.ack_received = 1;
	else if (sig == SIGUSR2)
		g_client_bonus.all_received = 1;
}

static void	ft_send_bit(int pid, char c)
{
	int	bit;
	int	counter;

	bit = 0;
	while (bit < 8)
	{
		g_client_bonus.ack_received = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		counter = 0;
		while (!g_client_bonus.ack_received)
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

static int	ft_digit_only(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_putstr_fd("PID must be all numbers!\n", 1);
			return (1);
		}
		str++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3 && argv[2][0] != '\0')
	{
		signal(SIGUSR1, ft_signal_handler);
		signal(SIGUSR2, ft_signal_handler);
		pid = ft_atoi(argv[1]);
		if (ft_strlen(argv[1]) < 1 || pid == 0)
		{
			ft_putstr_fd("Invalid PID\n", 1);
			return (1);
		}
		if (ft_digit_only(argv[1]))
			return (1);
		ft_send_str(pid, argv[2]);
		while (!g_client_bonus.all_received)
			usleep(42);
		ft_putstr_fd("All symbols received!\n", 1);
	}
	else
		ft_putstr_fd("Usage: ./client [PID] [STRING]\n", 1);
	return (0);
}
