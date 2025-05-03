/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bullet_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 17:50:56 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-03 17:50:56 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int check_bullet_bounds(t_game *data, int bullet_x, int bullet_y)
{
    if (bullet_y < 0 || bullet_y >= data->map->height || bullet_x < 0 || bullet_x >= data->map->width)
        return 0;
    return 1;
}

static void	bullet_move_left_animation(t_game *data)
{
		mlx_put_image_to_window(data->mlx, data->win, data->images->bullet_left,
			data->bullet->x, data->bullet->y);
}

int	move_left_the_bullet(t_game *data)
{
	float	copy_x;
	float	copy_y;
	float	bullet_x;
	float	bullet_y;

	copy_x = (float)data->player->x / (float)TILE_SIZE;
	copy_y = (float)data->player->y / (float)TILE_SIZE;
	bullet_x = (float)data->bullet->x / (float)TILE_SIZE;
	bullet_y = (float)data->bullet->y / (float)TILE_SIZE;
	if (!data->bullet->active || data->bullet->direction != LEFT)
		return (0);
	if (!check_bullet_bounds(data, bullet_x, bullet_y))
        return 0;
	if ((data->map->map[(int)ceil(copy_y)][(int)ceil(copy_x) - 1] == '1')
		|| (data->map->map[(int)ceil(copy_y)][(int)ceil(copy_x) - 1] == 'M')
		|| (data->map->map[(int)ceil(copy_y)][(int)ceil(copy_x) - 1] == 'E'))
		{
			data->bullet->active = 0;
			return (0);
		}
		if (data->map->map[(int)ceil(bullet_y)][(int)ceil(bullet_x)] == 'C')
		{
			data->bullet->x -= BULLET_SPEED;
			data->map->map[(int)ceil(bullet_y)][(int)ceil(bullet_x)] = '0';
		}	
	if (data->map->map[(int)ceil(bullet_y)][(int)ceil(bullet_x)] != '0')
	{
		data->bullet->active = 0;
		return 0;
	}

	if (++data->bullet->frame_rate >= TANK_MOVE_ANIM_LIMIT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->bullet->x, data->bullet->x);
		data->bullet->frame_rate = 0;
		data->bullet->x -= BULLET_SPEED;
		bullet_x = (float)data->bullet->x / (float)TILE_SIZE;
		bullet_move_left_animation(data);
		if ((data->map->map[(int)ceil(bullet_y)][(int)ceil(bullet_x) - 1] == '1')
			|| (data->map->map[(int)ceil(bullet_y)][(int)ceil(bullet_x) - 1] == 'M')
			|| (data->map->map[(int)ceil(bullet_y)][(int)ceil(bullet_x) - 1] == 'E'))
		{
			mlx_put_image_to_window(data->mlx, data->win, data->images->background,
				data->bullet->x, data->bullet->y);
			data->bullet->active = 0;
			mlx_loop_hook(data->mlx, NULL, NULL);
		}
	}
	return (0);
}


void	handle_tank_bullet_left(t_game *data)
{
	init_tank_bullet(data);
	if ((data->map->map[(data->player->y) / TILE_SIZE]
		[(data->player->x - TILE_SIZE) / TILE_SIZE] != '1')
		|| (data->map->map[(data->player->y) / TILE_SIZE]
		[(data->player->x - TILE_SIZE) / TILE_SIZE] != 'M')
		|| (data->map->map[(data->player->y) / TILE_SIZE]
		[(data->player->x - TILE_SIZE) / TILE_SIZE] != 'E'))
		mlx_loop_hook(data->mlx, &move_left_the_bullet, data);
}
