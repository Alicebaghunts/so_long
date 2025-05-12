/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-02 13:55:15 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-02 13:55:15 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	tank_move_left_animation(t_game *data)
{
	data->player->tank_img = (data->player->tank_img + 1) % 2;
	if (data->player->tank_img == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->player->tank_left_1,
			data->player->x, data->player->y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->player->tank_left_2,
			data->player->x, data->player->y);
}

static int	move_left(t_game *data)
{
	float	copy_x;
	float	copy_y;

	copy_x = (float)data->player->x / (float)TILE_SIZE;
	copy_y = (float)data->player->y / (float)TILE_SIZE;
	if ((data->map->map[(int)ceil(copy_y)][(int)ceil(copy_x) - 1] == '1')
		|| (data->map->map[(int)ceil(copy_y)][(int)ceil(copy_x) - 1] == 'M')
		|| ((data->map->map[(int)ceil(copy_y)][(int)ceil(copy_x) - 1] == 'E')
		&& data->map->coin != 0))
		return (0);
	check_coin_and_exit(data, ceil(copy_x) - 1, ceil(copy_y));
	if (++data->player->frame_rate >= TANK_MOVE_ANIM_LIMIT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->player->x, data->player->y);
		data->player->frame_rate = 0;
		data->player->x -= 8;
		copy_x = (float)data->player->x / (float)TILE_SIZE;
		tank_move_left_animation(data);
		data->player->move_count++;
		if (data->player->move_count == 8)
			mlx_loop_hook(data->mlx, NULL, NULL);
	}
	return (0);
}

void	handle_move_left(t_game *data)
{
	data->player->move_count = 0;
	data->player->tank_img = 0;
	if (data->player->direction != LEFT)
	{
		data->player->direction = LEFT;
		mlx_put_image_to_window(data->mlx, data->win, data->player->tank_left_1,
			data->player->x, data->player->y);
		return ;
	}
	if (data->map->map[(data->player->y) / TILE_SIZE]
		[(data->player->x - TILE_SIZE) / TILE_SIZE] != '1'
		&& data->map->map[(data->player->y) / TILE_SIZE]
		[(data->player->x - TILE_SIZE) / TILE_SIZE] != 'M')
	{
		data->moves += 1;
		show_moves(data);
		mlx_loop_hook(data->mlx, &move_left, data);
	}
}
