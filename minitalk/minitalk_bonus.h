/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:14:33 by yousong           #+#    #+#             */
/*   Updated: 2024/09/07 20:26:33 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define _GNU_SOURCE
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include "libft/libft.h"

typedef struct s_client_bonus	t_client_bonus;

struct s_client_bonus
{
	volatile sig_atomic_t	ack_received;
	volatile sig_atomic_t	all_received;
};

void	write_bits(int sig, siginfo_t *info, void *s);

#endif