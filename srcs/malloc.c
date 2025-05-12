/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-28 11:14:49 by alisharu          #+#    #+#             */
/*   Updated: 2025-04-28 11:14:49 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*malloc_data(t_map *map)
{
	t_game	*data;

	data = malloc(sizeof(t_game));
	if (data == NULL)
	{
		ft_free_matrix(map->map);
		free(map);
		error_handling(MALLOC_ERROR);
	}
	data->map = map;
	data->images = malloc_img(data);
	data->player = malloc_tank(data);
	data->player->direction = 1;
	data->moves = 0;
	return (data);
}

t_map_images	*malloc_img(t_game *data)
{
	t_map_images	*img;

	img = (t_map_images *)malloc(sizeof(t_map_images));
	if (!img)
	{
		ft_free_matrix(data->map->map);
		free(data->map);
		free(data);
		error_handling(MALLOC_ERROR);
	}
	return (img);
}

t_player	*malloc_tank(t_game *data)
{
	t_player	*tank;

	tank = (t_player *)malloc(sizeof(t_player));
	if (!tank)
	{
		free(data->images);
		ft_free_matrix(data->map->map);
		free(data->map);
		free(data);
		error_handling(MALLOC_ERROR);
	}
	return (tank);
}
