/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-13 11:16:56 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-13 11:16:56 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_tank_img(t_game *data)
{
	if (!data || !data->player)
		return ;
	if (data->player && data->player->tank_up_1)
		mlx_destroy_image(data->mlx, data->player->tank_up_1);
	if (data->player && data->player->tank_up_2)
		mlx_destroy_image(data->mlx, data->player->tank_up_2);
	if (data->player && data->player->tank_down_1)
		mlx_destroy_image(data->mlx, data->player->tank_down_1);
	if (data->player && data->player->tank_down_2)
		mlx_destroy_image(data->mlx, data->player->tank_down_2);
	if (data->player && data->player->tank_left_1)
		mlx_destroy_image(data->mlx, data->player->tank_left_1);
	if (data->player && data->player->tank_left_2)
		mlx_destroy_image(data->mlx, data->player->tank_left_2);
	if (data->player && data->player->tank_right_1)
		mlx_destroy_image(data->mlx, data->player->tank_right_1);
	if (data->player && data->player->tank_right_2)
		mlx_destroy_image(data->mlx, data->player->tank_right_2);
}

void	free_characters_1(t_game *data)
{
	if (!data || !data->images)
		return ;
	if (data->images && data->images->background)
		mlx_destroy_image(data->mlx, data->images->background);
	if (data->images && data->images->wall)
		mlx_destroy_image(data->mlx, data->images->wall);
	if (data->images && data->images->gerb)
		mlx_destroy_image(data->mlx, data->images->gerb);
	if (data->images && data->images->metal)
		mlx_destroy_image(data->mlx, data->images->metal);
	if (data->images && data->images->coin_star)
		mlx_destroy_image(data->mlx, data->images->coin_star);
	if (data->images && data->images->coin_bomb)
		mlx_destroy_image(data->mlx, data->images->coin_bomb);
}

void	free_all_characters(t_game *data)
{
	if (data)
	{
		if (data->player)
			free_tank_img(data);
		if (data->images)
			free_characters_1(data);
	}
}

void	free_all_data(t_game *data)
{
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map && data->map->map)
		ft_free_matrix(data->map->map);
	if (data->map)
		free(data->map);
	if (data->player)
		free(data->player);
	if (data->images)
		free(data->images);
	if (data)
		free(data);
}

void	ft_free_matrix(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}
