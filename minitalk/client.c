/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:14:43 by yousong           #+#    #+#             */
/*   Updated: 2024/09/07 13:15:51 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_bit(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		bit++;
	}
}

static void ft_send_str(pid_t pid, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_send_bit(pid, str[i]);
		i++;
	}
	ft_send_bit(pid, '\n');
	ft_send_bit(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3 && argv[2][0] != '\0')
	{
		pid = ft_atoi(argv[1]);
		if (pid < 100 || pid > 99998)
		{
			ft_putstr_fd("Invalid PID\n", 1);
			return (1);
		}
		ft_send_str(pid, argv[2]);
	}
	else
		ft_putstr_fd("Usage: ./client [PID] [STRING]\n", 1);
	return (0);
}