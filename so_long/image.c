/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:49:34 by yousong           #+#    #+#             */
/*   Updated: 2024/09/05 11:35:21 by yousong          ###   ########.fr       */
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
	render.exitx = mlx_xpm_file_to_image(mlx, "./images/exitx.xpm",
			&height, &width);
	render.land = mlx_xpm_file_to_image(mlx, "./images/land.xpm",
			&height, &width);
	render.nami = mlx_xpm_file_to_image(mlx, "./images/nami.xpm",
			&height, &width);
	render.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm",
			&height, &width);
	return (render);
}

void	put_img(t_game *g, int h, int w, int index)
{
	char	tile;
	void	*img;

	tile = g->str_line[index];
	img = g->img.land;
	if (tile == '1')
		img = g->img.wall;
	else if (tile == 'C')
		img = g->img.collect;
	else if (tile == 'P')
	{
		if (g->on_exit)
			img = g->img.exitx;
		else
			img = g->img.nami;
	}
	else if (tile == 'E')
	{
		if (g->all_col == g->coin_count)
			img = g->img.exit2;
		else
			img = g->img.exit1;
	}
	mlx_put_image_to_window(g->mlx, g->mlx_win, img, h * 64, w * 64);
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
			put_img(game, width, height, height * game->width + width);
			width++;
		}
		height++;
	}
}
