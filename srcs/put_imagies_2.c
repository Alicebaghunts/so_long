/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imagies_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:45:08 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/26 15:45:43 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_images_renesince(t_map_images *images, void *mlx)
{
	images->renesnace_1 = mlx_xpm_file_to_image(mlx,
			"textures/ren_1.xpm", &images->x, &images->y);
	images->renesnace_2 = mlx_xpm_file_to_image(mlx,
			"textures/ren_2.xpm", &images->x, &images->y);
	images->renesnace_3 = mlx_xpm_file_to_image(mlx,
			"textures/ren_3.xpm", &images->x, &images->y);
	images->renesnace_4 = mlx_xpm_file_to_image(mlx,
			"textures/ren_4.xpm", &images->x, &images->y);
}

void	init_images_water(t_map_images *images, void *mlx)
{
	images->water_1 = mlx_xpm_file_to_image(mlx,
			"textures/water_1.xpm", &images->x, &images->y);
	images->water_2 = mlx_xpm_file_to_image(mlx,
			"textures/water_2.xpm", &images->x, &images->y);
	images->water_3 = mlx_xpm_file_to_image(mlx,
			"textures/water_3.xpm", &images->x, &images->y);
}

void	init_images_kill(t_map_images *images, void *mlx)
{
	images->bom_1 = mlx_xpm_file_to_image(mlx, "textures/bom_1.xpm", &images->x, &images->y);
	images->bom_2 = mlx_xpm_file_to_image(mlx, "textures/bom_2.xpm", &images->x, &images->y);
	images->bom_3 = mlx_xpm_file_to_image(mlx, "textures/bom_3.xpm", &images->x, &images->y);
}

void	init_characters(t_map_images *images, void *mlx)
{
	images->ice = mlx_xpm_file_to_image(mlx, "textures/ice.xpm", &images->x, &images->y);
	images->wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &images->x, &images->y);
	images->metal = mlx_xpm_file_to_image(mlx, "textures/metal.xpm", &images->x, &images->y);
	images->grass = mlx_xpm_file_to_image(mlx, "textures/grass.xpm", &images->x, &images->y);
	images->pulya = mlx_xpm_file_to_image(mlx, "textures/pulya.xpm", &images->x, &images->y);
	images->gerb = mlx_xpm_file_to_image(mlx, "textures/gerb.xpm", &images->x, &images->y);
	images->background = mlx_xpm_file_to_image(mlx,
			"textures/background.xpm", &images->x, &images->y);
}
