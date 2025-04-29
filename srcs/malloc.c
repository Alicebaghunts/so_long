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

void	*malloc_img(t_map *map)
{
	t_map_images	*img;

	img = (t_map_images *)malloc(sizeof(t_map_images));
	if (!img)
	{
		ft_free_matrix(map->map);
		free(map);
		perror("Memory allocation failed for images");
		error_handling(MALLOC_ERROR);
	}
	return (img);
}

t_enemy	*malloc_enemy(t_map *map, t_map_images *img)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
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

t_player	*malloc_tank(t_map *map, t_map_images *img, t_enemy *enemy)
{
	t_player	*tank;

	tank = (t_player *)malloc(sizeof(t_player));
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