/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:52:09 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/24 23:11:14 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
void	render_map(t_map *map)
{
	void			*mlx;
	void			*win;
	t_images		*img;
	t_tank_images	*tank;
	t_put_images	put_data;

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

	put_data.mlx = mlx;
	put_data.win = win;
	put_data.map = map;
	put_data.images = img;
	put_data.tank = tank;
	put_data.enemy = NULL;
	put_images(&put_data);
	mlx_loop(mlx);
	free(img);
	free(tank);
	mlx_destroy_window(mlx, win);
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