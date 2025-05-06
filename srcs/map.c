/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:52:09 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/26 16:26:54 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_game(t_game *data)
{
	free_all_characters(data);
	free_all_data(data);
	exit(0);
}

int	key_hook(int keycode, t_game *data)
{
	if (keycode == ESC)
		close_game(data);
	call_move(keycode, data);
	return (0);
}

void	render_map(t_map *map)
{
	t_game	*data;

	data = malloc(sizeof(t_game));
	if (!data)
		error_handling(MALLOC_ERROR);
	data->map = map;
	data->bullet = malloc_bullet(data->map);
	data->images = malloc_img(data->bullet, data->map);
	data->enemy = malloc_enemy(data->map, data->images, data->bullet);
	data->player = malloc_tank(data->map, data->images, data->enemy,
			data->bullet);
	data->player->direction = 1;
	data->moves = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		perror("Failed to initialize mlx");
		free_all_characters(data);
		free_all_data(data);
		error_handling(MALLOC_ERROR);
	}
	data->win = mlx_new_window(data->mlx, map->width * TILE_SIZE, map->height
			* TILE_SIZE, "so_long");
	if (!data->win)
	{
		perror("Failed to create window");
		free_all_characters(data);
		free_all_data(data);
		error_handling(MALLOC_ERROR);
	}
	put_images(data);
	find_player_position(data);
	mlx_hook(data->win, 17, 0, close_game, data);
	mlx_hook(data->win, 2, 1, &key_hook, data);
	mlx_loop(data->mlx);
}

char	**resize_map(char **map, int *map_size)
{
	char	**new_map;
	int		i;

	*map_size *= 2;
	new_map = (char **)malloc(sizeof(char *) * (*map_size));
	if (!new_map)
		error_handling(MALLOC_ERROR);
	i = 0;
	while (i < *map_size / 2)
	{
		new_map[i] = map[i];
		i++;
	}
	free(map);
	return (new_map);
}

char	**read_in_map_file(int fd)
{
	char **map;
	char *line;
	char *pxik;
	int height;
	int map_size;

	map = malloc(sizeof(char *) * 10);
	if (!map)
		error_handling(MALLOC_ERROR);
	map_size = 10;
	height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		pxik = ft_strtrim(line, "\n");
		free(line);
		if (!pxik)
			error_handling(MALLOC_ERROR);
		if (height >= map_size)
			map = resize_map(map, &map_size);
		map[height++] = pxik;
	}
	if (height == 0)
	{
		free(map);
		error_handling(INVALID_MAP);
	}
	map[height] = NULL;
	return (map);
}