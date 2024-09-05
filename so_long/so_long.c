/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:31:22 by yousong           #+#    #+#             */
/*   Updated: 2024/09/05 11:00:10 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *message, t_game *game)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

void	game_init(t_game *game, char *map)
{
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	read_map(map, game);
	check_map(game);
	game->mlx_win = mlx_new_window(game->mlx,
			game->width * 64, game->height * 64, "so_long");
	game->on_exit = 0;
	set_image(game);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_ESC)
		ft_close_game(game);
	if (keysym == KEY_W)
		move_w(game);
	if (keysym == KEY_A)
		move_a(game);
	if (keysym == KEY_S)
		move_s(game);
	if (keysym == KEY_D)
		move_d(game);
	return (0);
}

int	ft_close_game(t_game *game)
{
	free_all_data(game);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	*nami;
	int		map_param_len;

	if (argc != 2)
		print_error("No map detected.\n", NULL);
	nami = malloc(sizeof(t_game));
	if (!nami)
	{
		write(1, "Error\n", 6);
		write(2, "Memory allocation failed\n", 25);
		exit(1);
	}
	map_param_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_param_len - 4], ".ber", 4))
		print_error("Map file must be a .ber file.\n", nami);
	game_init(nami, argv[1]);
	mlx_hook(nami->mlx_win, KeyPress, KeyPressMask, &handle_input, nami);
	mlx_hook(nami->mlx_win, DestroyNotify, 0, &ft_close_game, nami);
	mlx_loop(nami->mlx);
	free_all_data(nami);
	return (0);
}
