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

#include "so_long.h"
#include "mlx.h"

void	put_images_enemy(t_enemy_images *enemy, void *mlx)
{
	int	w;
	int	h;

	enemy->enemy_1 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_1.xpm", &w, &h);
	enemy->enemy_2 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_2.xpm", &w, &h);
	enemy->enemy_left_1 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_left_1.xpm", &w, &h);
	enemy->enemy_left_2 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_left_2.xpm", &w, &h);
	enemy->enemy_right_1 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_right_1.xpm", &w, &h);
	enemy->enemy_right_2 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_right_2.xpm", &w, &h);
	enemy->enemy_down_1 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_down_1.xpm", &w, &h);
	enemy->enemy_down_2 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_down_2.xpm", &w, &h);
	enemy->enemy_up_1 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_up_1.xpm", &w, &h);
	enemy->enemy_up_2 = mlx_xpm_file_to_image(mlx,
			"textures/enemy_up_2.xpm", &w, &h);
}

void	put_images_tank(t_tank_images *tank, void *mlx)
{
	int	w;
	int	h;

	tank->tank_1 = mlx_xpm_file_to_image(mlx,
			"textures/tank_1.xpm", &w, &h);
	tank->tank_2 = mlx_xpm_file_to_image(mlx,
			"textures/tank_2.xpm", &w, &h);
	tank->tank_left_1 = mlx_xpm_file_to_image(mlx,
			"textures/tank_left_1.xpm", &w, &h);
	tank->tank_left_2 = mlx_xpm_file_to_image(mlx,
			"textures/tank_left_2.xpm", &w, &h);
	tank->tank_right_1 = mlx_xpm_file_to_image(mlx,
			"textures/tank_right_1.xpm", &w, &h);
	tank->tank_right_2 = mlx_xpm_file_to_image(mlx,
			"textures/tank_right_2.xpm", &w, &h);
	tank->tank_down_1 = mlx_xpm_file_to_image(mlx,
			"textures/tank_down_1.xpm", &w, &h);
	tank->tank_down_2 = mlx_xpm_file_to_image(mlx,
			"textures/tank_down_2.xpm", &w, &h);
	tank->tank_up_1 = mlx_xpm_file_to_image(mlx,
			"textures/tank_up_1.xpm", &w, &h);
	tank->tank_up_2 = mlx_xpm_file_to_image(mlx,
			"textures/tank_up_2.xpm", &w, &h);
}


void	put_images_coin(t_images *images, void *mlx)
{
	int	w;
	int	h;

	images->coin_star = mlx_xpm_file_to_image(mlx,
			"textures/coin_star.xpm", &w, &h);
	images->coin_tank = mlx_xpm_file_to_image(mlx,
			"textures/coin_tank.xpm", &w, &h);
	images->coin_kaska = mlx_xpm_file_to_image(mlx,
			"textures/coin_kaska.xpm", &w, &h);
	images->coin_grandat = mlx_xpm_file_to_image(mlx,
			"textures/coin_bomb.xpm", &w, &h);
	images->coin_lapata = mlx_xpm_file_to_image(mlx,
			"textures/coin_lapata.xpm", &w, &h);
	images->coin_time = mlx_xpm_file_to_image(mlx,
			"textures/coin_time.xpm", &w, &h);
}