/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:14:58 by yousong           #+#    #+#             */
/*   Updated: 2024/09/04 14:47:47 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_error("Failed to open file.\n", game);
	line = get_next_line(fd);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->walk_count = 0;
	game->str_line = ft_strdup_without_nl(line);
	free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
		{
			tmp = ft_strjoin_without_nl(game->str_line, line);
			game->str_line = tmp;
		}
	}
	close(fd);
}

void	check_walls(t_game *game)
{
	int		i;

	i = 0;
	while (i < ft_strlen(game->str_line))
	{
		if (i < game->width)
		{
			if (game->str_line[i] != '1')
				print_error("Map not closed within walls.\n", game);
		}
		else if (i % game->width == 0 || i % game->width == game->width - 1)
		{
			if (game->str_line[i] != '1')
				print_error("Map not closed within walls.\n", game);
		}
		else if (i > ft_strlen(game->str_line) - game->width)
		{
			if (game->str_line[i] != '1')
				print_error("Map not closed within walls.\n", game);
		}
		i++;
	}
}

void	check_params(t_game *game)
{
	int	i;
	int	e_count;
	int	p_count;

	i = 0;
	e_count = 0;
	p_count = 0;
	game->all_col = 0;
	game->coin_count = 0;
	while (i++ < ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'E')
			e_count++;
		else if (game->str_line[i] == 'P')
			p_count++;
		else if (game->str_line[i] == 'C')
			game->all_col++;
	}
	if (e_count != 1)
		print_error("Map must only have 1 exit!\n", game);
	if (game->all_col == 0)
		print_error("Map must have at least one tangerine!\n", game);
	if (p_count != 1)
		print_error("Map must only have 1 starting point!\n", game);
}

void	check_map(t_game *game)
{
	if (game->height * game->width != ft_strlen(game->str_line))
		print_error("Map is not rectangular!\n", game);
	check_walls(game);
	check_params(game);
	if (check_valid_path(game) == 0)
		print_error("Map has no valid path!\n", game);
}
