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

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <string.h>
# include <sys/wait.h>

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
# define SP 32

# define UP 1
# define DOWN 3
# define LEFT 4
# define RIGHT 2

typedef struct s_map_images
{
	void			*background;
	void			*ice;
	void			*wall;
	void			*gerb;
	void			*metal;
	void			*grass;
	void			*pulya;
	void			*bullet_up;
	void			*bullet_down;
	void			*bullet_left;
	void			*bullet_right;
	void			*water_1;
	void			*water_2;
	void			*water_3;
	void			*coin_star;
	void			*coin_time;
	void			*coin_tank;
	void			*coin_kaska;
	void			*coin_lapata;
	void			*coin_bomb;
	void			*renesnace_1;
	void			*renesnace_2;
	void			*renesnace_3;
	void			*renesnace_4;
	void			*bom_1;
	void			*bom_2;
	void			*bom_3;
	int				x;
	int				y;
}					t_map_images;

typedef struct s_map
{
	char			**map;
	int				coin;
	int				exit;
	int				height;
	int				width;
	t_map_images	map_img;
}					t_map;

typedef struct s_player
{
	void			*tank_1;
	void			*tank_2;
	void			*tank_left_1;
	void			*tank_left_2;
	void			*tank_right_1;
	void			*tank_right_2;
	void			*tank_down_1;
	void			*tank_down_2;
	void			*tank_up_1;
	void			*tank_up_2;
	int				start_x;
	int				start_y;
	int				x;
	int				y;
	int				w;
	int				h;
	int				direction;
	int				move_count;
	int				frame_rate;
	int				tank_img;
	int				shoot_img;
	int				is_moving;
	int				frame_counter;
}					t_player;

typedef struct s_enemy
{
	void			*enemy_1;
	void			*enemy_2;
	void			*enemy_left_1;
	void			*enemy_left_2;
	void			*enemy_right_1;
	void			*enemy_right_2;
	void			*enemy_down_1;
	void			*enemy_down_2;
	void			*enemy_up_1;
	void			*enemy_up_2;
	int				start_x;
	int				start_y;
	int				x;
	int				y;
}					t_enemy;

typedef struct s_bullet
{
	int				x;
	int				y;
	int				direction;
	int				active;
	int				frame_rate;
	int				bullet_count;
	float			copy_bullet_x;
	float			copy_bullet_y;
	float			copy_player_x;
	float			copy_player_y;
}					t_bullet;

typedef struct s_coin
{
	int				x;
	int				y;
	int				frame;
}					t_coin;

typedef struct s_game
{
	int				x;
	int				y;
	void			*mlx;
	void			*win;

	int				current_coin;

	t_coin			*coins;
	int				coin_count;

	t_map			*map;
	t_map_images	*images;
	t_player		*player;
	t_enemy			*enemy;
	t_bullet		*bullet;
	int				moves;
}					t_game;

int					is_rectangular(t_map *matrix);
int					check_and_open_map_file(char *path);
int					checking_argument(char *str);
void				error_handling(int num);
void				ft_free_matrix(char **arr);
void				malloc_map(t_map *map);
void				init_map_first(t_map *map, int width, int height);
char				**read_in_map_file(int fd);
char				**resize_map(char **map, int *map_size);
void				print_matrix(char **matrix);
int					find_height(t_map *map);
int					find_width(t_map *map);
int					checking_walls(t_map *map);
int					checking_exits(t_map *map);
int					checking_coins(t_map *map);
int					checking_position(t_map *map);
int					checking_all_characters(t_map *map);
//
void				fill_exit(char **map, int x, int y);
void				fill_coin(char **map, int x, int y, int *coin_count);
char				**copy_map(t_map *map);
int					is_exit_reachable(t_game *game);
int					has_minimum_two_coins(t_game *game);
void				print_map(char **map, int height);
void				render_map(t_map *map);
//
void				checking(t_map *map, int fd);
int					checking_valid_way_to_exit(t_map *map);
int					checking_valid_way_to_coin(t_map *map);
int					check_valid_path_to_coins(t_map *map);
int					check_valid_path_to_exit(t_map *map);
void				flood_fill(char **map, int startX, int startY,
						int **visited, t_map *m);
//

void				init_images_renesince(t_map_images *images, void *mlx);
void				init_images_water(t_map_images *images, void *mlx);
void				init_images_kill(t_map_images *images, void *mlx);
void				init_characters(t_map_images *images, void *mlx);
void				init_images_enemy(t_enemy *enemy, void *mlx);
void				init_images_tank(t_player *tank, void *mlx);
void				init_images_coin(t_map_images *images, void *mlx);
void				putting(t_game *data);
void				put_images(t_game *data);
void				put_img_mandatory(t_game *data);
void				put_img_bonus_1(t_game *data);
void				put_img_bonus_2(t_game *data);
void				error_handling_map(t_map *map, int fd);
void				find_player_position(t_game *game);
//
t_bullet			*malloc_bullet(t_map *map);
t_map_images		*malloc_img(t_bullet *bullet, t_map *map);
t_enemy				*malloc_enemy(t_map *map, t_map_images *img,
						t_bullet *bullet);
t_player			*malloc_tank(t_map *map, t_map_images *img, t_enemy *enemy,
						t_bullet *bullet);
//
void				free_all_data(t_game *data);
void				free_all_characters(t_game *data);
void				free_characters_1(t_game *data);
void				free_characters_2(t_game *data);
void				free_coin_img(t_game *data);
void				free_tank_img(t_game *data);
void				free_enemy_img(t_game *data);
//
int					close_game(t_game *data);
void				call_move(int keycode, t_game *data);
void				check_coin_and_exit(t_game *data, int x, int y);

// move up
void				handle_move_up(t_game *data);
void				handle_move_down(t_game *data);
void				handle_move_left(t_game *data);
void				handle_move_right(t_game *data);

//
void				handle_tank_bullet_up(t_game *data);
void				handle_tank_bullet_down(t_game *data);
void				handle_tank_bullet_left(t_game *data);
void				handle_tank_bullet_right(t_game *data);
void				init_tank_bullet(t_game *data);

int					coin_anim(t_game *data);
int					key_hook(int keycode, t_game *data);
int					all_animation(t_game *data);

int					move_up(t_game *data);
void				remove_bullet(t_game *data);
int					check_bullet_bounds(t_game *data, int x, int y);
int					move_up_the_bullet(t_game *data);
int					move_down_the_bullet(t_game *data);
int					move_left_the_bullet(t_game *data);
int					move_right_the_bullet(t_game *data);

#endif

// W - water
// M - metal
// B - bomb
// L - lapata
// Z - zvezda
// K - kaska
// T - tank
// J - jam
// E - exit
// G - grass
