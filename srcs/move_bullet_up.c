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
#include <string.h>

static void	bullet_move_up_animation(t_game *data)
{
		mlx_put_image_to_window(data->mlx, data->win, data->images->bullet_up,
			data->bullet->x, data->bullet->y);
}

static int check_bullet_bounds(t_game *data, int bullet_x, int bullet_y)
{
    if (bullet_y < 0 || bullet_y >= data->map->height || bullet_x < 0
		|| bullet_x >= data->map->width)
        return 0;
    return 1;
}

static void checks_the_next_bullet_cordinate(t_game *data)
{
	if ((data->map->map[(int)ceil(data->bullet->copy_bullet_y)]
	[(int)ceil(data->bullet->copy_bullet_x)] == '0')
	&& (data->map->map[(int)ceil(data->bullet->copy_bullet_y) - 1]
	[(int)ceil(data->bullet->copy_bullet_x)] == 'M'
	|| data->map->map[(int)ceil(data->bullet->copy_bullet_y) - 1]
	[(int)ceil(data->bullet->copy_bullet_x)] == 'E'
	|| data->map->map[(int)ceil(data->bullet->copy_bullet_y) - 1]
	[(int)ceil(data->bullet->copy_bullet_x)] == '1'))
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->bullet->x, data->bullet->y);
			data->bullet->active = 0;
			mlx_loop_hook(data->mlx, NULL, NULL);
	}
}

static void	check_the_coin_part(t_game *data)
{
	if ((data->map->map[(int)ceil(data->bullet->copy_bullet_y)]
	[(int)ceil(data->bullet->copy_bullet_x)] == 'C')
	&& (data->map->map[(int)ceil(data->bullet->copy_bullet_y) - 1]
	[(int)ceil(data->bullet->copy_bullet_x)] != '1'))
	{
		data->map->coin--;
		data->map->map[(int)ceil(data->bullet->copy_bullet_y)]
		[(int)ceil(data->bullet->copy_bullet_x)] = '0';
	}
	else if ((data->map->map[(int)ceil(data->bullet->copy_bullet_y) - 1]
	[(int)ceil(data->bullet->copy_bullet_x)] == '1')
	&& (data->map->map[(int)ceil(data->bullet->copy_bullet_y)]
	[(int)ceil(data->bullet->copy_bullet_x)] == 'C'))
	{	
		data->map->coin--;
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->bullet->x, data->bullet->y);
		data->bullet->active = 0;
		mlx_loop_hook(data->mlx, NULL, NULL);
	}
}

static void check_bullet_exit_logic(t_game *data)
{
	if (((data->map->map[(int)ceil(data->bullet->copy_bullet_y) - 1]
	[(int)ceil(data->bullet->copy_bullet_x)] == '1')
	&& (data->map->map[(int)ceil(data->bullet->copy_bullet_y)]
	[(int)ceil(data->bullet->copy_bullet_x)] != 'C'))
	|| (data->map->map[(int)ceil(data->bullet->copy_bullet_y) - 1]
	[(int)ceil(data->bullet->copy_bullet_x)] == 'M')
	|| (data->map->map[(int)ceil(data->bullet->copy_bullet_y) - 1]
	[(int)ceil(data->bullet->copy_bullet_x)] == 'E'))
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->images->background, data->bullet->x, data->bullet->y);
			data->bullet->active = 0;
			mlx_loop_hook(data->mlx, NULL, NULL);
		}
}

int	move_up_the_bullet(t_game *data)
{
	data->bullet->copy_bullet_x = (float)data->bullet->x / (float)TILE_SIZE;
	data->bullet->copy_bullet_y = (float)data->bullet->y / (float)TILE_SIZE;
	if (!check_bullet_bounds(data, data->bullet->copy_bullet_x,
		data->bullet->copy_bullet_y))
        return 0;
	if (data->map->map[(int)ceil(data->bullet->copy_bullet_y)]
	[(int)ceil(data->bullet->copy_bullet_x)] != '0')
	{
		data->bullet->active = 0;
		return 0;
	}
	checks_the_next_bullet_cordinate(data);
	if (++data->bullet->frame_rate >= TANK_MOVE_ANIM_LIMIT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->bullet->x, data->bullet->y);
		data->bullet->frame_rate = 0;
		data->bullet->y -= BULLET_SPEED;
		data->bullet->copy_bullet_y = (float)data->bullet->y / (float)TILE_SIZE;
		bullet_move_up_animation(data);
		check_bullet_exit_logic(data);
		check_the_coin_part(data);
	}
	return (0);
}

void	handle_tank_bullet_up(t_game *data)
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