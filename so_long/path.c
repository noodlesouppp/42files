/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:42:00 by yousong           #+#    #+#             */
/*   Updated: 2024/09/04 14:51:05 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *g, int x, int y)
{
	int	index;

	if (x < 0 || x >= g->width || y < 0 || y >= g->height)
		return ;
	index = y * g->width + x;
	if (g->visited[index] || g->str_line[index] == '1')
		return ;
	g->visited[index] = 1;
	if (g->str_line[index] == 'C')
		g->coins_found++;
	else if (g->str_line[index] == 'E')
		g->exit_found = 1;
	flood_fill(g, x + 1, y);
	flood_fill(g, x - 1, y);
	flood_fill(g, x, y + 1);
	flood_fill(g, x, y - 1);
}

int	check_valid_path(t_game *g)
{
	int	start_x;
	int	start_y;
	int	i;

	start_x = -1;
	start_y = -1;
	i = 0;
	g->visited = ft_calloc(g->width * g->height, sizeof(char));
	g->coins_found = 0;
	g->exit_found = 0;
	while (i < g->width * g->height)
	{
		if (g->str_line[i] == 'P')
		{
			start_x = i % g->width;
			start_y = i / g->width;
			break ;
		}
		i++;
	}
	flood_fill(g, start_x, start_y);
	free(g->visited);
	return (g->coins_found == g->all_col && g->exit_found);
}
