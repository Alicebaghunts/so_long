/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-28 13:05:44 by alisharu          #+#    #+#             */
/*   Updated: 2025-04-28 13:05:44 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_enemy_img(t_game *data)
{
	if (data->enemy->enemy_1)
		mlx_destroy_image(data->mlx, data->enemy->enemy_1);
	if (data->enemy->enemy_2)
		mlx_destroy_image(data->mlx, data->enemy->enemy_2);
	if (data->enemy->enemy_up_1)
		mlx_destroy_image(data->mlx, data->enemy->enemy_up_1);
	if (data->enemy->enemy_up_2)
		mlx_destroy_image(data->mlx, data->enemy->enemy_up_2);
	if (data->enemy->enemy_down_1)
		mlx_destroy_image(data->mlx, data->enemy->enemy_down_1);
	if (data->enemy->enemy_down_2)
		mlx_destroy_image(data->mlx, data->enemy->enemy_down_2);
	if (data->enemy->enemy_left_1)
		mlx_destroy_image(data->mlx, data->enemy->enemy_left_1);
	if (data->enemy->enemy_left_2)
		mlx_destroy_image(data->mlx, data->enemy->enemy_left_2);
	if (data->enemy->enemy_right_1)
		mlx_destroy_image(data->mlx, data->enemy->enemy_right_1);
	if (data->enemy->enemy_right_2)
		mlx_destroy_image(data->mlx, data->enemy->enemy_right_2);
}

void	free_tank_img(t_game *data)
{
	if (data->player->tank_1)
		mlx_destroy_image(data->mlx, data->player->tank_1);
	if (data->player->tank_2)
		mlx_destroy_image(data->mlx, data->player->tank_2);
	if (data->player->tank_up_1)
		mlx_destroy_image(data->mlx, data->player->tank_up_1);
	if (data->player->tank_up_2)
		mlx_destroy_image(data->mlx, data->player->tank_up_2);
	if (data->player->tank_down_1)
		mlx_destroy_image(data->mlx, data->player->tank_down_1);
	if (data->player->tank_down_2)
		mlx_destroy_image(data->mlx, data->player->tank_down_2);
	if (data->player->tank_left_1)
		mlx_destroy_image(data->mlx, data->player->tank_left_1);
	if (data->player->tank_left_2)
		mlx_destroy_image(data->mlx, data->player->tank_left_2);
	if (data->player->tank_right_1)
		mlx_destroy_image(data->mlx, data->player->tank_right_1);
	if (data->player->tank_right_2)
		mlx_destroy_image(data->mlx, data->player->tank_right_2);
}


void	free_coin_img(t_game *data)
{
	if (data->images->coin_star)
		mlx_destroy_image(data->mlx, data->images->coin_star);
	if (data->images->coin_time)
		mlx_destroy_image(data->mlx, data->images->coin_time);
	if (data->images->coin_tank)
		mlx_destroy_image(data->mlx, data->images->coin_tank);
	if (data->images->coin_lapata)
		mlx_destroy_image(data->mlx, data->images->coin_lapata);
	if (data->images->coin_kaska)
		mlx_destroy_image(data->mlx, data->images->coin_kaska);
	if (data->images->coin_grandat)
		mlx_destroy_image(data->mlx, data->images->coin_grandat);
	if (data->images->coin_bomb)
		mlx_destroy_image(data->mlx, data->images->coin_bomb);
}

void	free_characters_1(t_game *data)
{
	if (data->images->background)
		mlx_destroy_image(data->mlx, data->images->background);
	if (data->images->ice)
		mlx_destroy_image(data->mlx, data->images->ice);
	if (data->images->wall)
		mlx_destroy_image(data->mlx, data->images->wall);
	if (data->images->gerb)
		mlx_destroy_image(data->mlx, data->images->gerb);
	if (data->images->metal)
		mlx_destroy_image(data->mlx, data->images->metal);
	if (data->images->grass)
		mlx_destroy_image(data->mlx, data->images->grass);
	if (data->images->pulya)
		mlx_destroy_image(data->mlx, data->images->pulya);
	if (data->images->water_1)
		mlx_destroy_image(data->mlx, data->images->water_1);
	if (data->images->water_2)
		mlx_destroy_image(data->mlx, data->images->water_2);
	if (data->images->water_3)
		mlx_destroy_image(data->mlx, data->images->water_3);
}


void	free_characters_2(t_game *data)
{
	if (data->images->renesnace_1)
		mlx_destroy_image(data->mlx, data->images->renesnace_1);
	if (data->images->renesnace_2)
		mlx_destroy_image(data->mlx, data->images->renesnace_2);
	if (data->images->renesnace_3)
		mlx_destroy_image(data->mlx, data->images->renesnace_3);
	if (data->images->renesnace_4)
		mlx_destroy_image(data->mlx, data->images->renesnace_4);
	if (data->images->bom_1)
		mlx_destroy_image(data->mlx, data->images->bom_1);
	if (data->images->bom_2)
		mlx_destroy_image(data->mlx, data->images->bom_2);
	if (data->images->bom_3)
		mlx_destroy_image(data->mlx, data->images->bom_3);
}

void	free_all_characters(t_game *data)
{
		free_enemy_img(data);
		free_tank_img(data);
		free_coin_img(data);
		free_characters_1(data);
		free_characters_2(data);
}

void	free_all_data(t_game *data)
{
	if (data->mlx && data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
	}
	if (data->map->map)
		ft_free_matrix(data->map->map);
	free(data);
}