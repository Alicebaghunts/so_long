/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imagies_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:29:01 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/26 15:45:40 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_images_enemy(t_enemy *enemy, void *mlx)
{
	enemy->enemy_1 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_1.xpm", &enemy->y, &enemy->x);
	enemy->enemy_2 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_2.xpm",&enemy->y, &enemy->x);
	enemy->enemy_left_1 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_left_1.xpm", &enemy->x, &enemy->y);
	enemy->enemy_left_2 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_left_2.xpm", &enemy->x, &enemy->y);
	enemy->enemy_right_1 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_right_1.xpm", &enemy->x, &enemy->y);
	enemy->enemy_right_2 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_right_2.xpm", &enemy->x, &enemy->y);
	enemy->enemy_down_1 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_down_1.xpm", &enemy->x, &enemy->y);
	enemy->enemy_down_2 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_down_2.xpm", &enemy->x, &enemy->y);
	enemy->enemy_up_1 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_up_1.xpm", &enemy->x, &enemy->y);
	enemy->enemy_up_2 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_up_2.xpm", &enemy->x, &enemy->y);
}

void	init_images_tank(t_player *tank, void *mlx)
{
	tank->tank_1 = mlx_xpm_file_to_image(mlx,
			"textures/tank_1.xpm", &tank->w, &tank->h);
	tank->tank_2 = mlx_xpm_file_to_image(mlx,
			"textures/tank_2.xpm", &tank->w, &tank->h);
	tank->tank_left_1 = mlx_xpm_file_to_image(mlx,
			"textures/tank_left_1.xpm", &tank->w, &tank->h);
	tank->tank_left_2 = mlx_xpm_file_to_image(mlx,
			"textures/tank_left_2.xpm", &tank->w, &tank->h);
	tank->tank_right_1 = mlx_xpm_file_to_image(mlx,
			"textures/tank_right_1.xpm", &tank->w, &tank->h);
	tank->tank_right_2 = mlx_xpm_file_to_image(mlx,
			"textures/tank_right_2.xpm", &tank->w, &tank->h);
	tank->tank_down_1 = mlx_xpm_file_to_image(mlx,
			"textures/tank_down_1.xpm", &tank->w, &tank->h);
	tank->tank_down_2 = mlx_xpm_file_to_image(mlx,
			"textures/tank_down_2.xpm", &tank->w, &tank->h);
	tank->tank_up_1 = mlx_xpm_file_to_image(mlx,
			"textures/tank_up_1.xpm", &tank->w, &tank->h);
	tank->tank_up_2 = mlx_xpm_file_to_image(mlx,
			"textures/tank_up_2.xpm", &tank->w, &tank->h);
}


void	init_images_coin(t_map_images *images, void *mlx)
{
	images->coin_star = mlx_xpm_file_to_image(mlx,
			"textures/coin_star.xpm", &images->x, &images->y);
	images->coin_tank = mlx_xpm_file_to_image(mlx,
			"textures/coin_tank.xpm", &images->x, &images->y);
	images->coin_kaska = mlx_xpm_file_to_image(mlx,
			"textures/coin_kaska.xpm", &images->x, &images->y);
	images->coin_grandat = mlx_xpm_file_to_image(mlx,
			"textures/coin_bomb.xpm", &images->x, &images->y);
	images->coin_lapata = mlx_xpm_file_to_image(mlx,
			"textures/coin_lapata.xpm", &images->x, &images->y);
	images->coin_time = mlx_xpm_file_to_image(mlx,
			"textures/coin_time.xpm", &images->x, &images->y);
}