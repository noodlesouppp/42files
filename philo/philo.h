/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:15:52 by yousong           #+#    #+#             */
/*   Updated: 2025/03/11 11:24:57 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define TRUE	1
# define FALSE	-2

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}				t_opcode;

typedef enum e_time_type
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}			t_time_type;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}				t_status;

typedef pthread_mutex_t	t_mtx;

typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}				t_fork;

typedef struct s_philo
{
	int			id;
	long		meal_count;
	long		last_meal;
	bool		full;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_mtx		philo_mtx;
	t_table		*table;
}				t_philo;

struct	s_table
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_limit_meals;
	long		start_sim;
	bool		end_sim;
	bool		all_threads_ready;
	long		nbr_threads;
	t_mtx		table_mtx;
	t_mtx		print_mtx;
	t_fork		*forks;
	t_philo		*philos;
	pthread_t	monitor;
};

/* utils.c */
void	print_err(const char *error);
long	ft_atol(const char *str);

/* parsing.c */
int		parse_input(t_table *table, char **argv);

/* handlers.c */
int		thread_handler(pthread_t *thread, void *(*rout)(void *),
			void *data, t_opcode opcode);
int		mutex_handler(t_mtx *mutex, t_opcode opcode);

/* init.c */
int		data_init(t_table *table);

/* simulation.c */
void	simulation(t_table *table);

/* get_and_set.c */
void	set_bool(t_mtx *mutex, bool *target, bool value);
bool	get_bool(t_mtx *mutex, bool *target);
void	set_long(t_mtx *mutex, long *target, long value);
long	get_long(t_mtx *mutex, long *target);
bool	simulation_fin(t_table *table);

/* synchro.c */
void	wait_all_threads(t_table *table);
long	get_time(t_time_type type);
void	incr_thread(t_mtx *mutex, long *target);
bool	all_threads_running(t_mtx *mutex, long *threads, long num_of_philo);

/* print_status.c */
void	print_status(t_philo *philo, const char status);

/* monitor.c */
void	*monitor_dinner(void *data);

/* actions.c */
void	thinking(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);

/* free_all.c */
void	free_table(t_table *table);

#endif