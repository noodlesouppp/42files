/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:34:29 by yousong           #+#    #+#             */
/*   Updated: 2024/09/04 14:53:24 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_linux/mlx.h"
# include "./get_next_line.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				65307
# define KEY_W					119
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100

typedef struct s_img {
	void	*nami;
	void	*collect;
	void	*land;
	void	*exit1;
	void	*exit2;
	void	*wall;
}				t_img;

typedef struct s_game {
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	int		height;
	int		width;
	int		all_col;
	int		coin_count;
	int		walk_count;
	char	*str_line;
	char	*visited;
	int		coins_found;
	int		exit_found;
}				t_game;

void	free_all_data(t_game *game);
void	free_images(t_game *game);

t_img	img_init(void *mlx);
void	put_img(t_game *g, int w, int h);
void	set_image(t_game *game);

void	read_map(char *filename, t_game *game);
void	check_walls(t_game *game);
void	check_params(t_game *game);
void	check_map(t_game *game);

void	flood_fill(t_game *game, int x, int y);
int		check_valid_path(t_game *game);

char	*ft_strdup_without_nl(char *s);
int		ft_strlcpy_without_nl(char *dst, char *src, int len);
char	*ft_strjoin_without_nl(char *s1, char *s2);

void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);
int		clear_game(t_game *game);

int		main(int argc, char **argv);
int		handle_input(int keysym, t_game *game);
void	game_init(t_game *game, char *map);
int		ft_close_game(t_game *game);
void	print_error(char *message, t_game *game);

#endif
