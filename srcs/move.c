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

void	check_valid_exit(t_game *data, int x, int y)
{
	if (data->map->map[y][x] == 'E' && data->map->coin == 0)
	{
		printf("Congratulations! You won");
		free_all_characters(data);
		free_all_data(data);
		exit(0);
	}
}

void	move_left(t_game *data)
{
	int	count;
	int	tile_x;
	int	tile_y;
	int	new_x;

	count = 1;
	new_x = data->player->x - TILE_SIZE;
	if (data->map->map[data->player->y / TILE_SIZE][new_x / TILE_SIZE] == '1'
		|| ((data->map->map[data->player->y / TILE_SIZE]
		[new_x / TILE_SIZE]  == 'E') && data->map->coin != 0))
			return;
	if (data->direction != 4)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->player->tank_left_1,
			data->player->x, data->player->y);
		data->direction = 4;
		return ;
	}
	data->player->x -= 16;
	while (data->player->x % TILE_SIZE != 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->player->x + 16, data->player->y);
		if (count % 2 == 1)
			mlx_put_image_to_window(data->mlx, data->win, data->player->tank_left_2,
				data->player->x, data->player->y);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->player->tank_left_1,
				data->player->x, data->player->y);
		count++;
		data->player->x -= 16;
	}
	tile_x = data->player->x / TILE_SIZE;
	tile_y = data->player->y / TILE_SIZE;
	if (data->map->map[tile_y][tile_x] == 'C')
	{
		data->map->map[tile_y][tile_x] = '0';
		data->map->coin--;
	}
	if (data->map->map[tile_y][tile_x] == 'E' && data->map->coin == 0)
	{
		printf("Congratulations! You won in %d moves.\n", data->moves + 1);
		free_all_characters(data);
		free_all_data(data);
		exit(0);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images->background,
		data->player->x + 16, data->player->y);
	mlx_put_image_to_window(data->mlx, data->win, data->player->tank_left_1,
		data->player->x, data->player->y);
	data->moves++;
}

void	call_move(int keycode, t_game *data)
{
	data->player->frame_rate = 0;
	if (data->player->x % TILE_SIZE != 0 || data->player->y % TILE_SIZE != 0)
   		return ;
	if (keycode == W)
	{
		handle_move_up(data);
	}
	else if (keycode == S)
	{
		handle_move_down(data);
	}
	else if (keycode == A)
	{
		handle_move_left(data);
	}
	else if (keycode == D)
	{
		handle_move_right(data);
	}
}
