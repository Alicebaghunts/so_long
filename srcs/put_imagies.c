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

#include "../includes/so_long.h"

void	put_images(t_game *data)
{
	if (!data->images || !data->player || !data->enemy)
		error_handling(MALLOC_ERROR);
	init_characters(data->images, data->mlx);
	init_images_kill(data->images, data->mlx);
	init_images_coin(data->images, data->mlx);
	init_images_tank(data->player, data->mlx);
	init_images_enemy(data->enemy, data->mlx);
	init_images_water(data->images, data->mlx);
	init_images_renesince(data->images, data->mlx);
	putting(data);
}

void	put_img_mandatory(t_game *data)
{
	if (data->map->map[data->y][data->x] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->wall, data->x * 64, data->y * 64);
	else if (data->map->map[data->y][data->x] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->background, data->x * 64, data->y * 64);
	else if (data->map->map[data->y][data->x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->player->tank_1, data->x * 64, data->y * 64);
	else if (data->map->map[data->y][data->x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->gerb, data->x * 64, data->y * 64);
	else if (data->map->map[data->y][data->x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->coin_star, data->x * 64, data->y * 64);
}

void	put_img_bonus_1(t_game *data)
{
	if (data->map->map[data->y][data->x] == 'B')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->coin_bomb, data->x * 64, data->y * 64);
	else if (data->map->map[data->y][data->x] == 'L')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->coin_lapata, data->x * 64, data->y * 64);
	else if (data->map->map[data->y][data->x] == 'Z')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->coin_star, data->x * 64, data->y * 64);
	else if (data->map->map[data->y][data->x] == 'K')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->coin_kaska, data->x * 64, data->y * 64);
	else if (data->map->map[data->y][data->x] == 'T')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->coin_time, data->x * 64, data->y * 64);
	else if (data->map->map[data->y][data->x] == 'J')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->coin_time, data->x * 64, data->y * 64);
	else if (data->map->map[data->y][data->x] == 'G')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->grass, data->x * 64, data->y * 64);
}

void	put_img_bonus_2(t_game *data)
{
	if (data->map->map[data->y][data->x] == 'W')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->water_1, data->x * 64, data->y * 64);
	else if (data->map->map[data->y][data->x] == 'M')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->metal, data->x * 64, data->y * 64);
	else if (data->map->map[data->y][data->x] == 'G')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->grass, data->x * 64, data->y * 64);
}

void	putting(t_game *data)
{
	data->y = 0;
	while (data->y < data->map->height)
	{
		data->x = 0;
		while (data->x < data->map->width)
		{
			put_img_mandatory(data);
			put_img_bonus_1(data);
			put_img_bonus_2(data);
			data->x++;
		}
		data->y++;
	}
}
