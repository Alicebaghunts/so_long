/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imagies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:29:01 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/22 17:54:36 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

typedef struct s_images
{
	void	*brick_wall;
	void	*metal_wall;
	void	*grass;
	void	*wather;
	void	*background;
	void	*ice;
}	t_images;

// void	put_images(t_images *images)
// {

// }

// void	put_wall(t_map*	map)
// {
// 	int	y;

// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			if (map->map[y][x] == '1')
// 				mlx_put_image_to_window(mlx, win, wall_img, x * 64, y * 64);
// 			x++;
// 		}
// 		y++;
// 	}
// }