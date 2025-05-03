/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bullet_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 17:22:41 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-03 17:22:41 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <math.h>

static void	bullet_move_down_animation(t_game *data)
{
		mlx_put_image_to_window(data->mlx, data->win, data->images->bullet_down,
			data->bullet->x, data->bullet->y);
}

static int check_bullet_bounds(t_game *data, int bullet_x, int bullet_y)
{
	if (bullet_y < 0 || bullet_y >= data->map->height || bullet_x < 0 || bullet_x >= data->map->width)
		return (0);
	return (1);
}


int	move_down_the_bullet(t_game *data)
{
	float	copy_x;
	float	copy_y;
	float	bullet_x;
	float	bullet_y;

	copy_x = (float)data->player->x / (float)TILE_SIZE;
	copy_y = (float)data->player->y / (float)TILE_SIZE;
	bullet_x = (float)data->bullet->x / (float)TILE_SIZE;
	bullet_y = (float)data->bullet->y / (float)TILE_SIZE;
	if (!data->bullet->active || data->bullet->direction != DOWN)
		return (0);
	if (!check_bullet_bounds(data, bullet_x, bullet_y))
		return (0);
	if ((data->map->map[(int)floor(copy_y)][(int)floor(copy_x)] == '1')
		|| (data->map->map[(int)floor(copy_y)][(int)floor(copy_x)] == 'M')
		|| (data->map->map[(int)floor(copy_y)][(int)floor(copy_x)] == 'E'))
		{
			data->bullet->active = 0;
			return (0);
		}
		if (data->map->map[(int)floor(bullet_y)][(int)floor(bullet_x)] == 'C')
		{
			data->bullet->y += BULLET_SPEED;
			data->map->map[(int)floor(bullet_y)][(int)floor(bullet_x)] = '0';
		}	
	if (data->map->map[(int)floor(bullet_y)][(int)floor(bullet_x)] != '0')
	{
		data->bullet->active = 0;
		return (0);
	}

	if (++data->bullet->frame_rate >= TANK_MOVE_ANIM_LIMIT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->bullet->x, data->bullet->y);
		data->bullet->frame_rate = 0;
		data->bullet->y += BULLET_SPEED;
		bullet_y = (float)data->bullet->y / (float)TILE_SIZE;
		bullet_move_down_animation(data);
		if ((data->map->map[(int)floor(bullet_y) + 1][(int)floor(bullet_x)] == '1')
			|| (data->map->map[(int)floor(bullet_y) + 1][(int)floor(bullet_x)] == 'M')
			|| (data->map->map[(int)floor(bullet_y) + 1][(int)floor(bullet_x)] == 'E'))
		{
			mlx_put_image_to_window(data->mlx, data->win, data->images->background,
				data->bullet->x, data->bullet->y);
			data->bullet->active = 0;
			mlx_loop_hook(data->mlx, NULL, NULL);
		}
	}
	return (0);
}

void	handle_tank_bullet_down(t_game *data)
{
	init_tank_bullet(data);
	if ((data->map->map[(data->player->y + TILE_SIZE) / TILE_SIZE]
		[(data->player->x) / TILE_SIZE] != '1')
		|| (data->map->map[(data->player->y + TILE_SIZE) / TILE_SIZE]
		[(data->player->x) / TILE_SIZE] != 'M')
		|| (data->map->map[(data->player->y + TILE_SIZE) / TILE_SIZE]
		[(data->player->x) / TILE_SIZE] != 'E'))
		mlx_loop_hook(data->mlx, &move_down_the_bullet, data);
}
