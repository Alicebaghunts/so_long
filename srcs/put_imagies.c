/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imagies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:05:10 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/26 15:44:24 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	put_images(t_put_images *put_data)
{
	if (!put_data->images || !put_data->tank || !put_data->enemy)
		error_handling(MALLOC_ERROR);
	put_characters(put_data->images, put_data->mlx);
	put_images_kill(put_data->images, put_data->mlx);
	put_images_coin(put_data->images, put_data->mlx);
	put_images_tank(put_data->tank, put_data->mlx);
	put_images_enemy(put_data->enemy, put_data->mlx);
	put_images_water(put_data->images, put_data->mlx);
	put_images_renesince(put_data->images, put_data->mlx);
	putting(put_data);
}

void	put_img_mandatory(t_put_images *put_data)
{
	if (put_data->map->map[put_data->y][put_data->x] == '1')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->wall, put_data->x * 64, put_data->y * 64);
	else if (put_data->map->map[put_data->y][put_data->x] == '0')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->background, put_data->x * 64, put_data->y * 64);
	else if (put_data->map->map[put_data->y][put_data->x] == 'P')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->tank->tank_1, put_data->x * 64, put_data->y * 64);
	else if (put_data->map->map[put_data->y][put_data->x] == 'E')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->gerb, put_data->x * 64, put_data->y * 64);
	else if (put_data->map->map[put_data->y][put_data->x] == 'C')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->coin_star, put_data->x * 64, put_data->y * 64);
}

void	put_img_bonus_1(t_put_images *put_data)
{
	if (put_data->map->map[put_data->y][put_data->x] == 'B')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->coin_bomb, put_data->x * 64, put_data->y * 64);
	else if (put_data->map->map[put_data->y][put_data->x] == 'L')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->coin_lapata, put_data->x * 64, put_data->y * 64);
	else if (put_data->map->map[put_data->y][put_data->x] == 'Z')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->coin_star, put_data->x * 64, put_data->y * 64);
	else if (put_data->map->map[put_data->y][put_data->x] == 'K')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->coin_kaska, put_data->x * 64, put_data->y * 64);
	else if (put_data->map->map[put_data->y][put_data->x] == 'T')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->coin_time, put_data->x * 64, put_data->y * 64);
	else if (put_data->map->map[put_data->y][put_data->x] == 'J')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->coin_time, put_data->x * 64, put_data->y * 64);
	else if (put_data->map->map[put_data->y][put_data->x] == 'G')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->grass, put_data->x * 64, put_data->y * 64);
}

void	put_img_bonus_2(t_put_images *put_data)
{
	if (put_data->map->map[put_data->y][put_data->x] == 'W')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->water_1, put_data->x * 64, put_data->y * 64);
	else if (put_data->map->map[put_data->y][put_data->x] == 'M')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->metal, put_data->x * 64, put_data->y * 64);
	else if (put_data->map->map[put_data->y][put_data->x] == 'G')
		mlx_put_image_to_window(put_data->mlx, put_data->win,
			put_data->images->grass, put_data->x * 64, put_data->y * 64);
}

void	putting(t_put_images *put_data)
{
	int	x;
	int	y;

	y = 0;
	while (y < put_data->map->height)
	{
		x = 0;
		while (x < put_data->map->width)
		{
			put_img_mandatory(put_data);
			put_img_bonus_1(put_data);
			put_img_bonus_2(put_data);
			x++;
		}
		y++;
	}
}
