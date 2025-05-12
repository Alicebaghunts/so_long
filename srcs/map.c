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

void	render_map(t_map *map)
{
	t_game	*data;

	data = malloc_data(map);
	data->mlx = mlx_init();
	if (!data->mlx)
		close_game(data);
	data->win = mlx_new_window(data->mlx, map->width * TILE_SIZE, map->height
			* TILE_SIZE, "so_long");
	if (!data->win)
		close_game(data);
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

static char	**malloc_copy_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 10);
	if (!map)
		error_handling(MALLOC_ERROR);
	return (map);
}

static void	check_height(int height, char **map)
{
	if (height == 0)
	{
		free(map);
		error_handling(INVALID_MAP);
	}
}

char	**read_in_map_file(int fd)
{
	char	**map;
	char	*line;
	char	*pxik;
	int		height;
	int		map_size;

	map = malloc_copy_map();
	map_size = 10;
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		pxik = ft_strtrim(line, "\n");
		free(line);
		if (!pxik)
			error_handling(MALLOC_ERROR);
		if (height >= map_size)
			map = resize_map(map, &map_size);
		map[height++] = pxik;
		line = get_next_line(fd);
	}
	check_height(height, map);
	return (map[height] = NULL, map);
}
