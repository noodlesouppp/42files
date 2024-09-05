/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:32 by yousong           #+#    #+#             */
/*   Updated: 2024/09/05 11:30:13 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_movement(t_game *g, int current, int next)
{
	char	next_tile;

	next_tile = g->str_line[next];
	if (next_tile != '1')
	{
		if (next_tile == 'C')
			g->coin_count++;
		else if (next_tile == 'E' && g->all_col == g->coin_count)
			clear_game(g);
		if (g->on_exit)
			g->str_line[current] = 'E';
		else
			g->str_line[current] = '0';
		g->str_line[next] = 'P';
		g->on_exit = (next_tile == 'E');
		g->walk_count++;
		ft_printf("%d\n", g->walk_count);
		set_image(g);
	}
}

void	move_w(t_game *g)
{
	int	i;

	i = 0;
	while (g->str_line[i] != 'P' && g->str_line[i] != '\0')
		i++;
	if (g->str_line[i] == 'P')
		handle_movement(g, i, i - g->width);
}

void	move_a(t_game *g)
{
	int	i;

	i = 0;
	while (g->str_line[i] != 'P' && g->str_line[i] != '\0')
		i++;
	if (g->str_line[i] == 'P')
		handle_movement(g, i, i - 1);
}

void	move_s(t_game *g)
{
	int	i;

	i = 0;
	while (g->str_line[i] != 'P' && g->str_line[i] != '\0')
		i++;
	if (g->str_line[i] == 'P')
		handle_movement(g, i, i + g->width);
}

void	move_d(t_game *g)
{
	int	i;

	i = 0;
	while (g->str_line[i] != 'P' && g->str_line[i] != '\0')
		i++;
	if (g->str_line[i] == 'P')
		handle_movement(g, i, i + 1);
}
