/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imagies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-13 11:18:22 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-13 11:18:22 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_characters(t_map_images *images, void *mlx)
{
	images->wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &images->x,
			&images->y);
	images->metal = mlx_xpm_file_to_image(mlx, "textures/metal.xpm", &images->x,
			&images->y);
	images->gerb = mlx_xpm_file_to_image(mlx, "textures/gerb.xpm", &images->x,
			&images->y);
	images->background = mlx_xpm_file_to_image(mlx, "textures/background.xpm",
			&images->x, &images->y);
	images->coin_star = mlx_xpm_file_to_image(mlx, "textures/coin_star.xpm",
			&images->x, &images->y);
	images->coin_bomb = mlx_xpm_file_to_image(mlx, "textures/coin_bomb.xpm",
			&images->x, &images->y);
}

void	init_images_tank(t_player *tank, void *mlx)
{
	tank->tank_1 = mlx_xpm_file_to_image(mlx, "textures/tank_1.xpm", &tank->w,
			&tank->h);
	tank->tank_2 = mlx_xpm_file_to_image(mlx, "textures/tank_2.xpm", &tank->w,
			&tank->h);
	tank->tank_left_1 = mlx_xpm_file_to_image(mlx, "textures/tank_left_1.xpm",
			&tank->w, &tank->h);
	tank->tank_left_2 = mlx_xpm_file_to_image(mlx, "textures/tank_left_2.xpm",
			&tank->w, &tank->h);
	tank->tank_right_1 = mlx_xpm_file_to_image(mlx, "textures/tank_right_1.xpm",
			&tank->w, &tank->h);
	tank->tank_right_2 = mlx_xpm_file_to_image(mlx, "textures/tank_right_2.xpm",
			&tank->w, &tank->h);
	tank->tank_down_1 = mlx_xpm_file_to_image(mlx, "textures/tank_down_1.xpm",
			&tank->w, &tank->h);
	tank->tank_down_2 = mlx_xpm_file_to_image(mlx, "textures/tank_down_2.xpm",
			&tank->w, &tank->h);
	tank->tank_up_1 = mlx_xpm_file_to_image(mlx, "textures/tank_up_1.xpm",
			&tank->w, &tank->h);
	tank->tank_up_2 = mlx_xpm_file_to_image(mlx, "textures/tank_up_2.xpm",
			&tank->w, &tank->h);
}

void	put_img_mandatory(t_game *data)
{
	if (data->map->map[data->y][data->x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->images->wall,
			data->x * TILE_SIZE, data->y * TILE_SIZE);
	else if (data->map->map[data->y][data->x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->x * TILE_SIZE, data->y * TILE_SIZE);
	else if (data->map->map[data->y][data->x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player->tank_1,
			data->x * TILE_SIZE, data->y * TILE_SIZE);
	else if (data->map->map[data->y][data->x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->images->gerb,
			data->x * TILE_SIZE, data->y * TILE_SIZE);
	else if (data->map->map[data->y][data->x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->images->coin_star,
			data->x * TILE_SIZE, data->y * TILE_SIZE);
	else if (data->map->map[data->y][data->x] == 'M')
		mlx_put_image_to_window(data->mlx, data->win, data->images->metal,
			data->x * TILE_SIZE, data->y * TILE_SIZE);
	else if (data->map->map[data->y][data->x] == 'B')
		mlx_put_image_to_window(data->mlx, data->win, data->images->coin_bomb,
			data->x * TILE_SIZE, data->y * TILE_SIZE);
}

void	put_images(t_game *data)
{
	if (!data->images || !data->player)
		error_handling(MALLOC_ERROR);
	init_characters(data->images, data->mlx);
	init_images_tank(data->player, data->mlx);
	putting(data);
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
			data->x++;
		}
		data->y++;
	}
}
