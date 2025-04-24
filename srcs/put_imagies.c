/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imagies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:05:10 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/24 19:06:55 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	put_wall(t_map *map, t_images *images, void *mlx, void *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, images->wall, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	put_water(t_map *map, t_images *images, void *mlx, void *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'W')
				mlx_put_image_to_window(mlx, win, images->wather_1, x * 64, y * 64);
			x++;
		}
		y++;
	}
}



