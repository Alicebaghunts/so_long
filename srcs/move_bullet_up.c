/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_shoot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-02 15:12:12 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-02 15:12:12 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <math.h>

void	init_tank_bullet(t_game *data)
{
	if (data->bullet->active == 1)
		return ;
	data->bullet->direction = data->player->direction;

	if (data->player->direction == UP)
	{
		data->bullet->x = data->player->x;
		data->bullet->y = data->player->y - TILE_SIZE;
	}
	else if (data->player->direction == DOWN)
	{
		data->bullet->x = data->player->x;
		data->bullet->y = data->player->y + TILE_SIZE;
	}
	else if (data->player->direction == LEFT)
	{
		data->bullet->x = data->player->x - TILE_SIZE;
		data->bullet->y = data->player->y;
	}
	else if (data->player->direction == RIGHT)
	{
		data->bullet->x = data->player->x + TILE_SIZE;
		data->bullet->y = data->player->y;
	}
	data->bullet->active = 1;
}

static void	bullet_move_up_animation(t_game *data)
{
		mlx_put_image_to_window(data->mlx, data->win, data->images->bullet_up,
			data->bullet->x, data->bullet->y);
}

int	move_up_the_bullet(t_game *data)
{
	float	copy_x;
	float	copy_y;
	float	bullet_x;
	float	bullet_y;

	copy_x = (float)data->player->x / (float)TILE_SIZE;
	copy_y = (float)data->player->y / (float)TILE_SIZE;
	bullet_x = (float)data->bullet->x / (float)TILE_SIZE;
	bullet_y = (float)data->bullet->y / (float)TILE_SIZE;
	if (!data->bullet->active || data->bullet->direction != UP)
		return (0);
	if ((data->map->map[(int)ceil(copy_y)][(int)ceil(copy_x)] == '1')
		|| (data->map->map[(int)ceil(copy_y)][(int)ceil(copy_x)] == 'M')
		|| (data->map->map[(int)ceil(copy_y)][(int)ceil(copy_x)] == 'E'))
		{
			data->bullet->active = 0;
			return (0);
		}
	if (data->map->map[(int)ceil(bullet_y)][(int)ceil(bullet_x)] != '0')
	{
		data->bullet->active = 0;
		return (0);
	}

	if (++data->bullet->frame_rate >= TANK_MOVE_ANIM_LIMIT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->bullet->x, data->bullet->y);
		data->bullet->frame_rate = 0;
		data->bullet->y -= BULLET_SPEED;
		bullet_y = (float)data->bullet->y / (float)TILE_SIZE;
		bullet_move_up_animation(data);
		if ((data->map->map[(int)ceil(bullet_y) - 1][(int)ceil(bullet_x)] == '1')
		|| (data->map->map[(int)ceil(bullet_y) - 1][(int)ceil(bullet_x)] == 'M')
		|| (data->map->map[(int)ceil(bullet_y) - 1][(int)ceil(bullet_x)] == 'E'))
		{
			mlx_put_image_to_window(data->mlx, data->win, data->images->background,
				data->bullet->x, data->bullet->y);
			mlx_loop_hook(data->mlx, NULL, NULL);
		}
	}
	return (0);
}

void	handle_tank_bullet(t_game *data)
{
	init_tank_bullet(data);
	if ((data->map->map[(data->player->y - TILE_SIZE) / TILE_SIZE]
		[(data->player->x) / TILE_SIZE] != '1')
		|| (data->map->map[(data->player->y - TILE_SIZE) / TILE_SIZE]
		[(data->player->x) / TILE_SIZE] != 'M')
		|| (data->map->map[(data->player->y - TILE_SIZE) / TILE_SIZE]
		[(data->player->x) / TILE_SIZE] != 'E'))
		mlx_loop_hook(data->mlx, &move_up_the_bullet, data);
}
