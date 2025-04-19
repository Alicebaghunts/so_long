/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-19 12:25:53 by alisharu          #+#    #+#             */
/*   Updated: 2025-04-19 12:25:53 by alisharu         ###   ########.fr       */
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
int		checking_all_characters(t_map *map);



#endif