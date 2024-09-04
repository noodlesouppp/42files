/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:49:34 by yousong           #+#    #+#             */
/*   Updated: 2024/09/04 14:46:50 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	render;
	int		height;
	int		width;

	render.collect = mlx_xpm_file_to_image(mlx, "./images/collect.xpm",
			&height, &width);
	render.exit1 = mlx_xpm_file_to_image(mlx, "./images/exit1.xpm",
			&height, &width);
	render.exit2 = mlx_xpm_file_to_image(mlx, "./images/exit2.xpm",
			&height, &width);
	render.land = mlx_xpm_file_to_image(mlx, "./images/land.xpm",
			&height, &width);
	render.nami = mlx_xpm_file_to_image(mlx, "./images/nami.xpm",
			&height, &width);
	render.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm",
			&height, &width);
	return (render);
}

void	put_img(t_game *g, int h, int w)
{
	if (g->str_line[w * g->width + h] == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.wall,
			h * 64, w * 64);
	else if (g->str_line[w * g->width + h] == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.collect,
			h * 64, w * 64);
	else if (g->str_line[w * g->width + h] == 'P')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.nami,
			h * 64, w * 64);
	else if (g->str_line[w * g->width + h] == 'E'
		&& g->all_col == g->coin_count)
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.exit2,
			h * 64, w * 64);
	else if (g->str_line[w * g->width + h] == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.exit1,
			h * 64, w * 64);
	else
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.land,
			h * 64, w * 64);
}

void	set_image(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			put_img(game, width, height);
			width++;
		}
		height++;
	}
}
