/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:25:19 by yousong           #+#    #+#             */
/*   Updated: 2024/09/04 12:43:31 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all_data(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->str_line);
	free(game);
}

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.nami);
	mlx_destroy_image(game->mlx, game->img.collect);
	mlx_destroy_image(game->mlx, game->img.land);
	mlx_destroy_image(game->mlx, game->img.exit1);
	mlx_destroy_image(game->mlx, game->img.exit2);
	mlx_destroy_image(game->mlx, game->img.wall);
}