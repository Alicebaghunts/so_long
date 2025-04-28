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

#include "so_long.h"

void	free_all(t_map *map, t_images *img, t_enemy_images *enemy,
		t_tank_images *tank)
{
	free(img);
	free(enemy);
	free(tank);
	free(map->map);
	free(map);
}

void	render_map(t_map *map)
{
	t_put_images	*put_data;

	put_data = malloc(sizeof(t_put_images));
	put_data->images = malloc_img(put_data->map);
	put_data->enemy = malloc_enemy(put_data->map, put_data->images);
	put_data->tank = malloc_tank(put_data->map, put_data->images, put_data->enemy);
	put_data->mlx = mlx_init();
	if (!put_data->mlx)
	{
		perror("Failed to initialize mlx");
		// free_all(map, img, enemy, tank);
		error_handling(MALLOC_ERROR);
	}
	put_data->win = mlx_new_window(put_data->mlx, map->width * 64, map->height * 64, "so_long");
	if (!put_data->win)
	{
		perror("Failed to create window");
		// free_all(map, img, enemy, tank);
		mlx_destroy_display(put_data->mlx);
		free(put_data->mlx);
		error_handling(MALLOC_ERROR);
	}
	put_data->map = map;
	put_images(put_data);
	mlx_loop(put_data->mlx);
	// free_all(map, img, enemy, tank);
	// free_all_data();
	// if (win)
	// 	mlx_destroy_window(mlx, win);
	// if (mlx)
	// 	mlx_destroy_display(mlx);
	// free(mlx);
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
	char	**map;
	char	*line;
	char	*pxik;
	int		height;
	int		map_size;

	map = (char **)malloc(sizeof(char *) * 10);
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
