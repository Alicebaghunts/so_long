/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:25:53 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/24 23:07:12 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define INVALID_ARGUMENT 1
# define INVALID_PATH 2
# define INVALID_FILE 3
# define INVALID_MAP 4
# define MALLOC_ERROR 5

typedef struct s_map
{
	char	**map;
	int		coin;
	int		exits;
	int		height;
	int		width;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
	int	coin;
}	t_player;

typedef struct s_game
{
	t_player	player;
	t_map		map;
	int			is_running;
}	t_game;

typedef struct s_images
{
	void	*background;
	void	*ice;
	void	*wall;
	void	*gerb;
	void	*metal;
	void	*grass;
	void	*pulya;
	void	*water_1;
	void	*water_2;
	void	*water_3;
	void	*coin_star;
	void	*coin_time;
	void	*coin_tank;
	void	*coin_kaska;
	void	*coin_grandat;
	void	*coin_lapata;
	void	*coin_bomb;
	void	*renesnace_1;
	void	*renesnace_2;
	void	*renesnace_3;
	void	*renesnace_4;
	void	*bom_1;
	void	*bom_2;
	void	*bom_3;
}	t_images;

typedef struct s_tank_images
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
}	t_tank_images;

typedef struct s_enemy_images
{
	void	*enemy_1;
	void	*enemy_2;
	void	*enemy_left_1;
	void	*enemy_left_2;
	void	*enemy_right_1;
	void	*enemy_right_2;
	void	*enemy_down_1;
	void	*enemy_down_2;
	void	*enemy_up_1;
	void	*enemy_up_2;
}	t_enemy_images;

typedef struct s_put_images
{
	int				x;
	int				y;
	void			*mlx;
	void			*win;
	t_map			*map;
	t_images		*images;
	t_tank_images	*tank;
	t_enemy_images	*enemy;
}	t_put_images;

int		is_rectangular(t_map *matrix);
int		check_and_open_map_file(char *path);
int		checking_argument(char *str);
void	error_handling(int num);
void	ft_free_matrix(char **arr);
void	malloc_map(t_map *map);
void	init_map_first(t_map *map, int width, int height);
char	**read_in_map_file(int fd);
char	**resize_map(char **map, int *map_size);
void	print_matrix(char **matrix);
int		find_height(t_map *map);
int		find_width(t_map *map);
int		checking_walls(t_map *map);
int		checking_exits(t_map *map);
int		checking_coins(t_map *map);
int		checking_position(t_map *map);
int		checking_all_characters(t_map *map);
//
void	fill_exit(char **map, int x, int y);
void	fill_coin(char **map, int x, int y, int *coin_count);
char	**copy_map(t_map *map);
int		is_exit_reachable(t_game *game);
int		has_minimum_two_coins(t_game *game);
void	find_player_position(t_game *game);
void	print_map(char **map, int height);
void	render_map(t_map *map);
//
void	checking(t_map *map, int fd);
int		checking_valid_way_to_exit(t_map *map);
int		checking_valid_way_to_coin(t_map *map);
int		check_valid_path_to_coins(t_map *map);
int		check_valid_path_to_exit(t_map *map);
void	flood_fill(char **map, int startX, int startY, int **visited, t_map *m);
//

void	put_images_coin(t_images *images, void *mlx);
void	put_images_renesince(t_images *images, void *mlx);
void	put_images_water(t_images *images, void *mlx);
void	put_images_kill(t_images *images, void *mlx);
void	put_characters(t_images *images, void *mlx);
void	error_handling_map(t_map *map, int fd);
void	put_images_enemy(t_enemy_images *enemy, void *mlx);
void	put_images_tank(t_tank_images *tank, void *mlx);
void	put_images(t_put_images *put_data);
void	put_img_mandatory(t_put_images *put_data);
void	put_img_bonus(t_put_images *put_data);
void	putting(t_put_images *put_data);
//
#endif



//W - water
//M - metal
//B - bomb
//L - lapata
//Z - zvezda
//K - kaska
//T - tank
//J - jam
//E - exit
//G - grass
