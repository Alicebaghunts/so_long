/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:52:09 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/24 20:25:41 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	put_img_mandatory(t_map *map, void *mlx, void *win, int x, int y, t_images *img, t_tank_images *tank)
{
	if (map->map[y][x] == '1')
		mlx_put_image_to_window(mlx, win, img->wall, x * 64, y * 64);
	else if (map->map[y][x] == '0')
		mlx_put_image_to_window(mlx, win, img->background, x * 64, y * 64);
	else if (map->map[y][x] == 'P')
		mlx_put_image_to_window(mlx, win, tank->tank_1, x * 64, y * 64);
	else if (map->map[y][x] == 'E')
		mlx_put_image_to_window(mlx, win, img->gerb, x * 64, y * 64);
	else if (map->map[y][x] == 'C')
		mlx_put_image_to_window(mlx, win, img->coin_star, x * 64, y * 64);
}

void	put_img_bonus(t_map *map, void *mlx, void *win, int x, int y, t_images *img)
{
	if (map->map[y][x] == 'W')
		mlx_put_image_to_window(mlx, win, img->wather_1, x * 64, y * 64);
	else if (map->map[y][x] == 'M')
		mlx_put_image_to_window(mlx, win, img->metal, x * 64, y * 64);
	else if (map->map[y][x] == 'B')
		mlx_put_image_to_window(mlx, win, img->coin_bomb, x * 64, y * 64);
	else if (map->map[y][x] == 'L')
		mlx_put_image_to_window(mlx, win, img->coin_lapata, x * 64, y * 64);
	else if (map->map[y][x] == 'Z')
		mlx_put_image_to_window(mlx, win, img->coin_star, x * 64, y * 64);
	else if (map->map[y][x] == 'K')
		mlx_put_image_to_window(mlx, win, img->coin_kaska, x * 64, y * 64);
	else if (map->map[y][x] == 'T')
		mlx_put_image_to_window(mlx, win, img->coin_time, x * 64, y * 64);
	else if (map->map[y][x] == 'J')
		mlx_put_image_to_window(mlx, win, img->coin_time, x * 64, y * 64);
	else if (map->map[y][x] == 'G')
		mlx_put_image_to_window(mlx, win, img->grass, x * 64, y * 64);
}

void	render_map(t_map *map)
{
	void		*mlx;
	void		*win;
	t_images	*img;
	t_tank_images	*tank;

	img = (t_images *)malloc(sizeof(t_images));
	if (!img)
		error_handling(MALLOC_ERROR);
	tank = (t_tank_images *)malloc(sizeof(t_tank_images));
	if (!tank)
		error_handling(MALLOC_ERROR);
	mlx = mlx_init();
	if (!mlx)
		error_handling(MALLOC_ERROR);
	win = mlx_new_window(mlx, map->width * 64, map->height * 64, "so_long");
	if (!win)
		error_handling(MALLOC_ERROR);
	put_images(map, mlx, win, img, tank);
	mlx_loop(mlx);
	free(img);
	free(tank);
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
