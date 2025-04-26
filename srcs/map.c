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

#include "mlx.h"
#include "so_long.h"

void	*malloc_img(t_map *map)
{
	t_images	*img;

	img = (t_images *)malloc(sizeof(t_images));
	if (!img)
	{
		ft_free_matrix(map->map);
		free(map);
		perror("Memory allocation failed for images");
		error_handling(MALLOC_ERROR);
	}
	return (img);
}

t_enemy_images	*malloc_enemy(t_map *map, t_images *img)
{
	t_enemy_images	*enemy;

	enemy = (t_enemy_images *)malloc(sizeof(t_enemy_images));
	if (!enemy)
	{
		perror("Memory allocation failed for enemy images");
		free(img);
		ft_free_matrix(map->map);
		free(map);
		error_handling(MALLOC_ERROR);
	}
	return (enemy);
}

t_tank_images	*malloc_tank(t_map *map, t_images *img, t_enemy_images *enemy)
{
	t_tank_images	*tank;

	tank = (t_tank_images *)malloc(sizeof(t_tank_images));
	if (!tank)
	{
		perror("Memory allocation failed for tank images");
		free(img);
		free(enemy);
		ft_free_matrix(map->map);
		free(map);
		error_handling(MALLOC_ERROR);
	}
	return (tank);
}

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
	void			*mlx;
	void			*win;
	t_images		*img;
	t_tank_images	*tank;
	t_enemy_images	*enemy;
	t_put_images	put_data;

	img = malloc_img(map);
	enemy = malloc_enemy(map, img);
	tank = malloc_tank(map, img, enemy);
	mlx = mlx_init();
	if (!mlx)
	{
		perror("Failed to initialize mlx");
		free_all(map, img, enemy, tank);
		error_handling(MALLOC_ERROR);
	}
	win = mlx_new_window(mlx, map->width * 64, map->height * 64, "so_long");
	if (!win)
	{
		perror("Failed to create window");
		free_all(map, img, enemy, tank);
		mlx_destroy_display(mlx);
		free(mlx);
		error_handling(MALLOC_ERROR);
	}
	put_data.mlx = mlx;
	put_data.win = win;
	put_data.map = map;
	put_data.images = img;
	put_data.tank = tank;
	put_data.enemy = enemy;
	put_images(&put_data);
	mlx_loop(mlx);
	free_all(map, img, enemy, tank);
	if (win)
		mlx_destroy_window(mlx, win);
	if (mlx)
		mlx_destroy_display(mlx);
	free(mlx);
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
