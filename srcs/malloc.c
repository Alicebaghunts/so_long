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

#include "so_long.h"

void	*malloc_img(t_map *map)
{
	t_images	*img;

	img = (t_images *)malloc(sizeof(t_images));
	if (!img)
	{
		ft_free_matrix(map->map);
		free(map);
		perror("Memory allocation failed for images");
		error_handling(MALLOC_ERROR);
	}
	return (img);
}

t_enemy_images	*malloc_enemy(t_map *map, t_images *img)
{
	t_enemy_images	*enemy;

	enemy = (t_enemy_images *)malloc(sizeof(t_enemy_images));
	if (!enemy)
	{
		perror("Memory allocation failed for enemy images");
		free(img);
		ft_free_matrix(map->map);
		free(map);
		error_handling(MALLOC_ERROR);
	}
	return (enemy);
}

t_tank_images	*malloc_tank(t_map *map, t_images *img, t_enemy_images *enemy)
{
	t_tank_images	*tank;

	tank = (t_tank_images *)malloc(sizeof(t_tank_images));
	if (!tank)
	{
		perror("Memory allocation failed for tank images");
		free(img);
		free(enemy);
		ft_free_matrix(map->map);
		free(map);
		error_handling(MALLOC_ERROR);
	}
	return (tank);
}