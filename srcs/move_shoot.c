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
#include <stdio.h>

void handle_tank_shoot(t_game *data)
{
    if (data->bullet->active)
        return;
    data->bullet->direction = data->direction;

    if (data->direction == UP)
    {
        data->bullet->x = data->player->x;
        data->bullet->y = data->player->y - 64 -64 -64;
    }
    else if (data->direction == DOWN)
    {
        data->bullet->x = data->player->x;
        data->bullet->y = data->player->y + TILE_SIZE;
    }
    else if (data->direction == LEFT)
    {
        data->bullet->x = data->player->x - TILE_SIZE;
        data->bullet->y = data->player->y;
    }
    else if (data->direction == RIGHT)
    {
        data->bullet->x = data->player->x + TILE_SIZE;
        data->bullet->y = data->player->y;
    }

    data->bullet->active = 1;
}

static void	bullet_move_up_animation(t_game *data)
{
		mlx_put_image_to_window(data->mlx, data->win, data->images->pulya,
			data->player->x, data->player->y);
}

int	move_up_the_bullet(t_game *data)
{
	float	copy_x;
	float	copy_y;

	copy_x = (float)data->player->x / (float)TILE_SIZE;
	copy_y = (float)data->player->y / (float)TILE_SIZE;
	if (data->map->map[(int)ceil(copy_y) - 1][(int)ceil(copy_x)] == '1'
		|| (data->map->map[(int)ceil(copy_y) - 1][(int)ceil(copy_x)] == 'E'))
		return (0);
	if (++data->player->frame_rate >= TANK_MOVE_ANIM_LIMIT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			(int)copy_x, (int)copy_y);
		data->player->frame_rate = 0;
		data->player->y -= 32;
		copy_y = (float)data->player->y / (float)TILE_SIZE;
		bullet_move_up_animation(data);
		data->player->move_count++;
		check_coin_and_exit(data, copy_x, copy_y);
		if (data->player->move_count == 2)
			mlx_loop_hook(data->mlx, NULL, NULL);
	}
	return (0);
}

void	handle_tank_bullet(t_game *data)
{
	if (data->direction != UP)
	{
		data->direction = UP;
		mlx_put_image_to_window(data->mlx, data->win, data->player->tank_1,
			data->player->x, data->player->y);
		return ;
	}
	if (data->map->map[(data->player->y - TILE_SIZE) / TILE_SIZE]
		[(data->player->x) / TILE_SIZE] != '1')
		mlx_loop_hook(data->mlx, &move_up_the_bullet, data);
}
