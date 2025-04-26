/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imagies_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:45:08 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/26 15:45:43 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"


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

	images->water_1 = mlx_xpm_file_to_image(mlx,
			"textures/water_1.xpm", &w, &h);
	images->water_2 = mlx_xpm_file_to_image(mlx,
			"textures/water_2.xpm", &w, &h);
	images->water_3 = mlx_xpm_file_to_image(mlx,
			"textures/water_3.xpm", &w, &h);
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
