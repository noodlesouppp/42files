/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:32 by yousong           #+#    #+#             */
/*   Updated: 2024/09/04 12:45:04 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clear_game(t_game *game)
{
	game->walk_count++;
	ft_printf("%s %d %s\n", "You helped Nami in", game->walk_count, "steps!");
	free_all_data(game);
	exit(0);
}

void	move_w(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - g->width] == 'C')
		g->coin_count++;
	if (g->str_line[i - g->width] == 'E' && g->all_col == g->coin_count)
		clear_game(g);
	else if (g->str_line[i - g->width] != '1'
		&& g->str_line[i - g->width] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - g->width] = 'P';
		g->walk_count++;
		ft_printf("%d\n", g->walk_count);
		set_image(g);
	}
}

void	move_a(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - 1] == 'C')
		g->coin_count++;
	if (g->str_line[i - 1] == 'E' && g->all_col == g->coin_count)
		clear_game(g);
	else if (g->str_line[i - 1] != '1' && g->str_line[i - 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - 1] = 'P';
		g->walk_count++;
		ft_printf("%d\n", g->walk_count);
		set_image(g);
	}
}

void	move_s(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i + g->width] == 'C')
		g->coin_count++;
	if (g->str_line[i + g->width] == 'E' && g->all_col == g->coin_count)
		clear_game(g);
	else if (g->str_line[i + g->width] != '1'
		&& g->str_line[i + g->width] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + g->width] = 'P';
		g->walk_count++;
		ft_printf("%d\n", g->walk_count);
		set_image(g);
	}
}

void	move_d(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i + 1] == 'C')
		g->coin_count++;
	if (g->str_line[i + 1] == 'E' && g->all_col == g->coin_count)
		clear_game(g);
	else if (g->str_line[i + 1] != '1' && g->str_line[i + 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + 1] = 'P';
		g->walk_count++;
		ft_printf("%d\n", g->walk_count);
		set_image(g);
	}
}
