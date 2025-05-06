
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bullet_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 08:19:58 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-05 08:19:58 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

#include "../includes/so_long.h"
#include <math.h>

static void	checks_the_next_bullet_cordinate(t_game *data)
{
	int		bullet_x;
	int		bullet_y;
	int		next_x;
	char	next_tile;
	char	current_tile;

	bullet_x = (int)floor(data->bullet->copy_bullet_x);
	bullet_y = (int)floor(data->bullet->copy_bullet_y);
	next_x = bullet_x + 1;
	next_tile = data->map->map[bullet_y][next_x];
	current_tile = data->map->map[bullet_y][bullet_x];
	if ((current_tile == '0' || current_tile == 'C') && (next_tile == 'M'
			|| next_tile == 'E' || next_tile == '1'))
		remove_bullet(data);
}

static void	check_the_coin_part(t_game *data)
{
	int	bullet_x;
	int	bullet_y;
	int	next_x;

	bullet_x = (int)floor(data->bullet->copy_bullet_x);
	bullet_y = (int)floor(data->bullet->copy_bullet_y);
	next_x = bullet_x + 1;
	if (data->map->map[bullet_y][bullet_x] == 'C')
	{
		if (data->map->map[bullet_y][next_x] != '1'
			&& data->map->map[bullet_y][next_x] != 'M'
			&& data->map->map[bullet_y][next_x] != 'E')
		{
			data->map->coin--;
			data->map->map[bullet_y][bullet_x] = '0';
		}
		else
			remove_bullet(data);
	}
}

static void	check_bullet_exit_logic(t_game *data)
{
	int	bullet_x;
	int	bullet_y;
	int	next_x;

	bullet_x = (int)floor(data->bullet->copy_bullet_x);
	bullet_y = (int)floor(data->bullet->copy_bullet_y);
	next_x = bullet_x + 1;
	if ((((data->map->map[bullet_y][next_x] == '1')
			&& (data->map->map[bullet_y][next_x] != 'C'))
			|| (data->map->map[bullet_y][next_x] == 'M')
			|| (data->map->map[bullet_y][next_x] == 'E'))
			&& data->bullet->bullet_count == 8)
		remove_bullet(data);
}

static void	main_logic_bullet(t_game *data)
{
	if (++data->bullet->frame_rate >= TANK_MOVE_ANIM_LIMIT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			data->bullet->x, data->bullet->y);
		data->bullet->frame_rate = 0;
		data->bullet->x += BULLET_SPEED;
		data->bullet->copy_bullet_x = (float)data->bullet->x / (float)TILE_SIZE;
		data->bullet->bullet_count += 1;
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->bullet_right, data->bullet->x, data->bullet->y);
		check_bullet_exit_logic(data);
		check_the_coin_part(data);
	}
}

int	move_right_the_bullet(t_game *data)
{
	data->bullet->copy_bullet_x = (float)data->bullet->x / (float)TILE_SIZE;
	data->bullet->copy_bullet_y = (float)data->bullet->y / (float)TILE_SIZE;
	data->bullet->copy_player_x = (float)data->player->x / (float)TILE_SIZE;
	data->bullet->copy_player_y = (float)data->player->y / (float)TILE_SIZE;
	if (!check_bullet_bounds(data, data->bullet->copy_bullet_x,
			data->bullet->copy_bullet_y))
		return (0);
	checks_the_next_bullet_cordinate(data);
	if (data->bullet->bullet_count >= 8)
		return (remove_bullet(data), 0);
	main_logic_bullet(data);
	return (0);
}

