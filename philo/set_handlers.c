/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 05:41:25 by yousong           #+#    #+#             */
/*   Updated: 2025/03/10 00:06:01 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_handler(pthread_t *thread, void *(*rout)(void *),
	void *data, t_opcode opcode)
{
	if (opcode == CREATE)
	{
		if (pthread_create(thread, NULL, rout, data))
			return (FALSE);
	}
	else if (opcode == JOIN)
	{
		if (pthread_join(*thread, NULL))
			return (FALSE);
	}
	else if (opcode == DETACH)
	{
		if (pthread_detach(*thread))
			return (FALSE);
	}
	return (TRUE);
}

int	mutex_handler(t_mtx *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
	{
		if (pthread_mutex_lock(mutex))
			return (FALSE);
	}
	else if (opcode == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex))
			return (FALSE);
	}
	else if (opcode == INIT)
	{
		if (pthread_mutex_init(mutex, NULL))
			return (FALSE);
	}
	else if (opcode == DESTROY)
	{
		if (pthread_mutex_destroy(mutex))
			return (FALSE);
	}
	return (TRUE);
}
