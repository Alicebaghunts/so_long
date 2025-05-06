/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bullet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 15:44:30 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-06 15:44:30 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_tank_bullet_up(t_game *data)
{
	init_tank_bullet(data);
	if ((data->map->map[(data->player->y - TILE_SIZE)
				/ TILE_SIZE][(data->player->x) / TILE_SIZE] != '1')
		&& (data->map->map[(data->player->y - TILE_SIZE)
			/ TILE_SIZE][(data->player->x) / TILE_SIZE] != 'M')
		&& (data->map->map[(data->player->y - TILE_SIZE)
			/ TILE_SIZE][(data->player->x) / TILE_SIZE] != 'E'))
		mlx_loop_hook(data->mlx, &move_up_the_bullet, data);
}

void	handle_tank_bullet_down(t_game *data)
{
	init_tank_bullet(data);
	if ((data->map->map[(data->player->y + TILE_SIZE)
				/ TILE_SIZE][(data->player->x) / TILE_SIZE] != '1')
		&& (data->map->map[(data->player->y + TILE_SIZE)
			/ TILE_SIZE][(data->player->x) / TILE_SIZE] != 'M')
		&& (data->map->map[(data->player->y + TILE_SIZE)
			/ TILE_SIZE][(data->player->x) / TILE_SIZE] != 'E'))
		mlx_loop_hook(data->mlx, &move_down_the_bullet, data);
}


void	handle_tank_bullet_left(t_game *data)
{
	init_tank_bullet(data);
	if ((data->map->map[(data->player->y) / TILE_SIZE][(data->player->x
				- TILE_SIZE) / TILE_SIZE] != '1')
		&& (data->map->map[(data->player->y) / TILE_SIZE][(data->player->x
				- TILE_SIZE) / TILE_SIZE] != 'M')
		&& (data->map->map[(data->player->y) / TILE_SIZE][(data->player->x
				- TILE_SIZE) / TILE_SIZE] != 'E'))
		mlx_loop_hook(data->mlx, &move_left_the_bullet, data);
}

void	handle_tank_bullet_right(t_game *data)
{
	init_tank_bullet(data);
	if ((data->map->map[(data->player->y) / TILE_SIZE][(data->player->x
				+ TILE_SIZE) / TILE_SIZE] != '1')
		&& (data->map->map[(data->player->y) / TILE_SIZE][(data->player->x
				+ TILE_SIZE) / TILE_SIZE] != 'M')
		&& (data->map->map[(data->player->y) / TILE_SIZE][(data->player->x
				+ TILE_SIZE) / TILE_SIZE] != 'E'))
		mlx_loop_hook(data->mlx, &move_right_the_bullet, data);
}

