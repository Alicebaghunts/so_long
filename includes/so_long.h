/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-13 11:20:59 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-13 11:20:59 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>

# define INVALID_ARGUMENT 1
# define INVALID_PATH 2
# define INVALID_FILE 3
# define INVALID_MAP 4
# define MALLOC_ERROR 5

# define TANK_MOVE_ANIM_LIMIT 1024
# define BULLET_SPEED 32
# define TILE_SIZE 64
# define ESC 65307

# define W 119
# define S 115
# define A 97
# define D 100

# define UP 1
# define DOWN 3
# define LEFT 4
# define RIGHT 2

typedef struct s_map_images
{
	void	*background;
	void	*wall;
	void	*gerb;
	void	*metal;
	void	*coin_star;
	void	*coin_bomb;
	int		x;
	int		y;
}	t_map_images;

typedef struct s_map
{
	char	**map;
	int		coin;
	int		exit;
	int		height;
	int		width;
}	t_map;

typedef struct s_player
{
	void	*tank_1;
	void	*tank_2;
	void	*tank_left_1;
	void	*tank_left_2;
	void	*tank_right_1;
	void	*tank_right_2;
	void	*tank_down_1;
	void	*tank_down_2;
	void	*tank_up_1;
	void	*tank_up_2;
	int		start_x;
	int		start_y;
	int		x;
	int		y;
	int		w;
	int		h;
	int		direction;
	int		move_count;
	int		frame_rate;
	int		tank_img;
}	t_player;

typedef struct s_game
{
	int				x;
	int				y;
	int				moves;
	void			*mlx;
	void			*win;
	t_map			*map;
	t_map_images	*images;
	t_player		*player;
}	t_game;

int				is_rectangular(t_map *matrix);
int				check_and_open_map_file(char *path);
int				checking_argument(char *str);
int				find_height(t_map *map);
int				find_width(t_map *map);
int				is_exit_reachable(t_game *game);
int				has_minimum_two_coins(t_game *game);
int				checking_valid_way_to_exit(t_map *map);
int				checking_valid_way_to_coin(t_map *map);
int				check_valid_path_to_coins(t_map *map);
int				check_valid_path_to_exit(t_map *map);
int				checking_walls(t_map *map);
int				checking_exits(t_map *map);
int				checking_coins(t_map *map);
int				checking_position(t_map *map);
int				checking_all_characters(t_map *map);
int				close_game(t_game *data);
int				key_hook(int keycode, t_game *data);
int				find_player_y_cordinate(t_map *map);
int				find_player_x_cordinate(t_map *map);
int				flood_fill_for_e(t_map *map);
int				flood_fill_for_c(t_map *map);
void			find_player_position(t_game *game);
void			handle_move_up(t_game *data);
void			handle_move_down(t_game *data);
void			handle_move_right(t_game *data);
void			handle_move_left(t_game *data);
void			dfs(char **map, t_map *s, int i, int j);
void			show_moves(t_game *data);
void			error_handling(int num);
void			error_handling_map(t_map *map, int fd);
void			ft_free_matrix(char **arr);
void			init_map_first(t_map *map, int width, int height);
void			print_matrix(char **matrix);
void			fill_exit(char **map, int x, int y);
void			fill_coin(char **map, int x, int y, int *coin_count);
void			print_map(char **map, int height);
void			render_map(t_map *map);
void			checking(t_map *map, int fd);
void			check_coin_and_exit(t_game *data, int x, int y);
void			putting(t_game *data);
void			put_images(t_game *data);
void			put_img_mandatory(t_game *data);
void			init_images_tank(t_player *tank, void *mlx);
void			init_characters(t_map_images *images, void *mlx);
void			free_all_characters(t_game *data);
void			free_all_data(t_game *data);
void			call_move(int keycode, t_game *data);
char			**read_in_map_file(int fd);
char			**resize_map(char **map, int *map_size);
char			**copy_map(t_map *map);
t_game			position(t_map *map);
t_game			position_e(t_map *map, char **copy);
t_game			*malloc_data(t_map *map);
t_player		*malloc_tank(t_game *data);
t_player		*malloc_tank(t_game *data);
t_map_images	*malloc_img(t_game *data);

#endif
