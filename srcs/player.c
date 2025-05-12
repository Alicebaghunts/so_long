/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   payer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:55:39 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/21 22:55:56 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_game(t_game *data)
{
	free_all_characters(data);
	free_all_data(data);
	exit(0);
}

int	key_hook(int keycode, t_game *data)
{
	if (keycode == ESC)
		close_game(data);
	call_move(keycode, data);
	return (0);
}

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'P')
			{
				game->player->x = x * 64;
				game->player->y = y * 64;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	find_player_x_cordinate(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				x = x * 64;
				return (x);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

int	find_player_y_cordinate(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				y = y * 64;
				return (y);
			}
			x++;
		}
		y++;
	}
	return (-1);
}
