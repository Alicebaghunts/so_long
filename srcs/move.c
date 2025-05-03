/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:52:09 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/26 16:26:54 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	check_coin_and_exit(t_game *data, int x, int y)
{
	if (data->map->map[y][x] == 'C')
	{
		data->map->map[y][x] = '0';
		data->map->coin--;
		return ;
	}
	if (data->map->map[y][x] == 'E' && data->map->coin == 0)
	{
		free_all_characters(data);
		free_all_data(data);
		exit(0);
	}
}

void	call_move(int keycode, t_game *data)
{
	data->player->frame_rate = 0;
	data->bullet->frame_rate = 0;
	if (data->player->x % TILE_SIZE != 0 || data->player->y % TILE_SIZE != 0)
   		return ;
	if (keycode == W)
		handle_move_up(data);
	else if (keycode == S)
		handle_move_down(data);
	else if (keycode == A)
		handle_move_left(data);
	else if (keycode == D)
		handle_move_right(data);
	else if (keycode == SP && data->player->direction == UP)
		handle_tank_bullet_up(data);
	else if (keycode == SP && data->player->direction == DOWN)
		handle_tank_bullet_down(data);
	else if (keycode == SP && data->player->direction == RIGHT)
		handle_tank_bullet_up(data);
	else if (keycode == SP && data->player->direction == LEFT)
		handle_tank_bullet_left(data);
}