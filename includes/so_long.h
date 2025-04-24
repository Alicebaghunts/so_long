/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:25:53 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/23 00:27:23 by alisharu         ###   ########.fr       */
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
	void	*wather_1;
	void	*wather_2;
	void	*wather_3;
	void	*coin_star;
	void	*coin_time;
	void	*coin_tank;
	void	*coin_kaska;
	void	*coin_grandat;
	void	*coin_lapata;
	void	*renesnace_1;
	void	*renesnace_2;
	void	*renesnace_3;
	void	*renesnace_4;
	void	*bom_1;
	void	*bom_2;
	void	*bom_3;
	void	*bom_4;
	void	*bom_5;
	void	*bom_6;
	void	*bom_7;
	void	*bom_8;
	void	*bom_9;
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
}	t_tank_images;

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



#endif