/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:29:01 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/24 19:45:15 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"


void	put_images_enemy(t_enemy_images * enemy, void *mlx)
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
	enemy->enemy_up_1= mlx_xpm_file_to_image(mlx,
			"textures/enemy_up_1.xpm", &w, &h);
	enemy-> enemy_up_2= mlx_xpm_file_to_image(mlx,
			"textures/enemy_up_2.xpm", &w, &h);
}

void	put_images_tank(t_tank_images* tank, void *mlx)
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
	tank->tank_up_1= mlx_xpm_file_to_image(mlx,
			"textures/tank_up_1.xpm", &w, &h);
	tank-> tank_up_2= mlx_xpm_file_to_image(mlx,
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

void	put_images_renesince(t_images *images, void *mlx)
{
	int	w;
	int	h;

	images->renesnace_1 = mlx_xpm_file_to_image(mlx,
			"textures/ren_1.xpm", &w, &h);
	images->renesnace_2 = mlx_xpm_file_to_image(mlx,
			"textures/ren_2.xpm", &w, &h);
	images->renesnace_3 = mlx_xpm_file_to_image(mlx,
			"textures/ren_3.xpm", &w, &h);
	images->renesnace_4 = mlx_xpm_file_to_image(mlx,
			"textures/ren_4.xpm", &w, &h);
}

void	put_images_water(t_images *images, void *mlx)
{
	int	w;
	int	h;

	images->wather_1 = mlx_xpm_file_to_image(mlx,
			"textures/wather_1.xpm", &w, &h);
	images->wather_2 = mlx_xpm_file_to_image(mlx,
			"textures/wather_2.xpm", &w, &h);
	images->wather_3 = mlx_xpm_file_to_image(mlx,
			"textures/wather_3.xpm", &w, &h);
}

void	put_images_kill(t_images *images, void *mlx)
{
	int	w;
	int	h;

	images->bom_1 = mlx_xpm_file_to_image(mlx, "textures/bom_1.xpm", &w, &h);
	images->bom_2 = mlx_xpm_file_to_image(mlx, "textures/bom_2.xpm", &w, &h);
	images->bom_3 = mlx_xpm_file_to_image(mlx, "textures/bom_3.xpm", &w, &h);
}

void	put_characters(t_images *images, void *mlx)
{
	int	w;
	int	h;

	images->ice = mlx_xpm_file_to_image(mlx, "textures/ice.xpm", &w, &h);
	images->wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &w, &h);
	images->metal = mlx_xpm_file_to_image(mlx, "textures/metal.xpm", &w, &h);
	images->grass = mlx_xpm_file_to_image(mlx, "textures/tress.xpm", &w, &h);
	images->pulya = mlx_xpm_file_to_image(mlx, "textures/pulya.xpm", &w, &h);
	images->gerb = mlx_xpm_file_to_image(mlx, "textures/gerb.xpm", &w, &h);
	images->background = mlx_xpm_file_to_image(mlx,
			"textures/background.xpm", &w, &h);
}
