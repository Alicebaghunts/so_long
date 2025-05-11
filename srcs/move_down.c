/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-02 12:35:11 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-02 12:35:11 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	tank_move_down_animation(t_game *data)
{
	data->player->tank_img = (data->player->tank_img + 1) % 2;
	if (data->player->tank_img == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->player->tank_down_1,
			data->player->x, data->player->y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->player->tank_down_2,
			data->player->x, data->player->y);
}

static int	move_down(t_game *data)
{
	float	copy_x;
	float	copy_y;

	copy_x = (float)data->player->x / (float)TILE_SIZE;
	copy_y = (float)data->player->y / (float)TILE_SIZE;
	if ((data->map->map[(int)floor(copy_y) + 1][(int)floor(copy_x)] == '1')
		|| (data->map->map[(int)floor(copy_y) + 1][(int)floor(copy_x)] == 'M')
		|| ((data->map->map[(int)floor(copy_y) + 1][(int)floor(copy_x)] == 'E')
		&& data->map->coin != 0))
		return (0);
	check_coin_and_exit(data, floor(copy_x), floor(copy_y) + 1);
	if (++data->player->frame_rate >= TANK_MOVE_ANIM_LIMIT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->player->x, data->player->y);
		data->player->frame_rate = 0;
		data->player->y += 8;
		copy_y = (float)data->player->y / (float)TILE_SIZE;
		tank_move_down_animation(data);
		data->player->move_count++;
		if (data->player->move_count == 8)
			mlx_loop_hook(data->mlx, NULL, NULL);
	}
	return (0);
}

void	handle_move_down(t_game *data)
{
	data->player->move_count = 0;
	data->player->tank_img = 0;
	if (data->player->direction != DOWN)
	{
		data->player->direction = DOWN;
		mlx_put_image_to_window(data->mlx, data->win, data->player->tank_down_1,
			data->player->x, data->player->y);
		return ;
	}
	if (data->map->map[(data->player->y + TILE_SIZE) / TILE_SIZE]
		[(data->player->x) / TILE_SIZE] != '1'
		&& data->map->map[(data->player->y + TILE_SIZE) / TILE_SIZE]
		[(data->player->x) / TILE_SIZE] != 'M')
		mlx_loop_hook(data->mlx, &move_down, data);
}
