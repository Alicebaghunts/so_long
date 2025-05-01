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

// void update_player(t_game *data)
// {
	
// 	int target_y = data->player->y + 64;
// 	int count = 1;
// 	if (--64 != )
// 	{
// 		// Clear old position
// 		mlx_put_image_to_window(data->mlx, data->win,
// 			data->images->background, data->player->x, data->player->y);

// 		// Move up a few pixels
// 		data->player->y -= 4; // adjust speed here

// 		// Draw with animation frame
// 		if (count % 2 == 0)
// 			mlx_put_image_to_window(data->mlx, data->win,
// 				data->player->tank_1, data->player->x, data->player->y);
// 		else
// 			mlx_put_image_to_window(data->mlx, data->win,
// 				data->player->tank_2, data->player->x, data->player->y);

// 		count++;
// 	}
// 	else
// 	{
// 		data->player->y = target_y;
// 		// data->player->is_moving = 0;
// 		count = 0;

// 		// Coin collection or exit check
// 		int tile_x = data->player->x / TILE_SIZE;
// 		int tile_y = data->player->y / TILE_SIZE;
// 		if (data->map->map[tile_y][tile_x] == 'C') {
// 			data->map->map[tile_y][tile_x] = '0';
// 			data->map->coin--;
// 		}
// 		if (data->map->map[tile_y][tile_x] == 'E' && data->map->coin == 0) {
// 			// TODO: Exit logic
// 		}
// 	}
// }


void	move_up(t_game *data)
{
	int	count;
	int new_y;
	int tile_x;
	int tile_y;

	count = 1;
	new_y = data->player->y - TILE_SIZE;
	if (data->map->map[new_y / TILE_SIZE][data->player->x / TILE_SIZE] == '1'
		|| ((data->map->map[new_y / TILE_SIZE]
		[data->player->x / TILE_SIZE] == 'E') && data->map->coin != 0))
		return;
	data->player->y -= 16;
	while (data->player->y % TILE_SIZE != 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->player->x, data->player->y + 16);
		if (count % 2 == 1)
			mlx_put_image_to_window(data->mlx, data->win, data->player->tank_2,
				data->player->x, data->player->y);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->player->tank_1,
				data->player->x, data->player->y);
		count++;
		data->player->y -= 16;
		tile_x = data->player->x / TILE_SIZE;
		tile_y = data->player->y / TILE_SIZE;
		if (data->map->map[tile_y][tile_x] == 'C')
		{
			data->map->map[tile_y][tile_x] = '0';
			data->map->coin--;
			printf("coin %d\n", data->map->coin);
		}
		if (data->map->map[tile_y][tile_x] == 'E' && data->map->coin == 0)
		{
			printf("Congratulations! You won in %d moves.\n", data->moves + 1);
			free_all_characters(data);
			free_all_data(data);
			exit(0);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images->background,
		data->player->x, data->player->y + 16);
	mlx_put_image_to_window(data->mlx, data->win, data->player->tank_1,
		data->player->x, data->player->y);
	data->moves++;
}

void	move_down(t_game *data)
{
	int	count;
	int	new_y;
	int	tile_x;
	int	tile_y;

	count = 1;
	new_y = data->player->y + TILE_SIZE;
	if (data->map->map[new_y / TILE_SIZE][data->player->x / TILE_SIZE] == '1'
		|| ((data->map->map[new_y / TILE_SIZE]
		[data->player->x / TILE_SIZE] == 'E') && data->map->coin != 0))
		return;
	data->player->y += 16;
	while (data->player->y % TILE_SIZE != 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->player->x, data->player->y - 16);
		if (count % 2 == 1)
			mlx_put_image_to_window(data->mlx, data->win,
				data->player->tank_down_2, data->player->x, data->player->y);
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->player->tank_down_1, data->player->x, data->player->y);
		count++;
		data->player->y += 16;
		tile_x = data->player->x / TILE_SIZE;
		tile_y = data->player->y / TILE_SIZE;
		if (data->map->map[tile_y][tile_x] == 'C')
		{
			data->map->map[tile_y][tile_x] = '0';
			data->map->coin--;
			printf("coin %d\n", data->map->coin);
		}
		if (data->map->map[tile_y][tile_x] == 'E' && data->map->coin == 0)
		{
			printf("Congratulations! You won in %d moves.\n", data->moves + 1);
			free_all_characters(data);
			free_all_data(data);
			exit(0);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images->background,
		data->player->x, data->player->y - 16);
	mlx_put_image_to_window(data->mlx, data->win, data->player->tank_down_1,
		data->player->x, data->player->y);
	data->moves++;
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
		tile_x = data->player->x / TILE_SIZE;
		tile_y = data->player->y / TILE_SIZE;
		if (data->map->map[tile_y][tile_x] == 'C')
		{
			data->map->map[tile_y][tile_x] = '0';
			data->map->coin--;
			printf("coin %d\n", data->map->coin);
		}
		if (data->map->map[tile_y][tile_x] == 'E' && data->map->coin == 0)
		{
			printf("Congratulations! You won in %d moves.\n", data->moves + 1);
			free_all_characters(data);
			free_all_data(data);
			exit(0);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images->background,
		data->player->x + 16, data->player->y);
	mlx_put_image_to_window(data->mlx, data->win, data->player->tank_left_1,
		data->player->x, data->player->y);
	data->moves++;
}


void	move_right(t_game *data)
{
	int	count;
	int	new_x;
	int	tile_x;
	int	tile_y;

	count = 1;
	new_x = data->player->x + TILE_SIZE;
	if (data->map->map[data->player->y / TILE_SIZE][new_x / TILE_SIZE] == '1'
		|| ((data->map->map[data->player->y / TILE_SIZE]
		[new_x / TILE_SIZE]  == 'E') && data->map->coin != 0))
		return;
	data->player->x += 16;
	while (data->player->x % TILE_SIZE != 0)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->background, data->player->x - 16, data->player->y);
		if (count % 2 == 1)
			mlx_put_image_to_window(data->mlx, data->win,
				data->player->tank_right_2, data->player->x, data->player->y);
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->player->tank_right_1, data->player->x, data->player->y);
		count++;
		data->player->x += 16;

		tile_x = data->player->x / TILE_SIZE;
		tile_y = data->player->y / TILE_SIZE;

		if (data->map->map[tile_y][tile_x] == 'C')
		{
			data->map->map[tile_y][tile_x] = '0';
			data->map->coin--;
			printf("coin %d\n", data->map->coin);
		}
		if (data->map->map[tile_y][tile_x] == 'E' && data->map->coin == 0)
		{
			printf("Congratulations! You won in %d moves.\n", data->moves + 1);
			free_all_characters(data);
			free_all_data(data);
			exit(0);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images->background,
		data->player->x - 16, data->player->y);
	mlx_put_image_to_window(data->mlx, data->win, data->player->tank_right_1,
		data->player->x, data->player->y);
	data->moves++;
}


void	call_move(int keycode, t_game *data)
{
	printf("keykode: %d\n", keycode);
	if (data->player->x % TILE_SIZE != 0 || data->player->y % TILE_SIZE != 0)
   		return ;
	if ((keycode == UP)
		&& data->map->map[(data->player->y - 16) / TILE_SIZE][(data->player->x) / TILE_SIZE] != '1')
	{
		move_up(data);
	}
	else if ((keycode == DOWN)
		&& data->map->map[(data->player->y + 16) / TILE_SIZE + 1][(data->player->x) / TILE_SIZE] != '1')
	{
		move_down(data);
	}
	else if ((keycode == LEFT)
		&& data->map->map[(data->player->y) / TILE_SIZE][(data->player->x - 16) / TILE_SIZE] != '1')
	{
		move_left(data);
	}
	else if ((keycode == RIGHT)
		&& data->map->map[(data->player->y) / TILE_SIZE][(data->player->x + 16) / TILE_SIZE + 1] != '1')
	{
		move_right(data);
	}
}
