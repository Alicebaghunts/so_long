/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-18 15:19:34 by alisharu          #+#    #+#             */
/*   Updated: 2025-04-18 15:19:34 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"

int main()
{
	void    *mlx;
    void    *win;

    int     width = 800;
    int     height = 600;

    mlx = mlx_init();

    win = mlx_new_window(mlx, width, height, "My first MLX window");

	for (int i = 0; i < 100; i++)
		mlx_pixel_put(mlx, win, 100 + i, 100 + i, 0xFFFFFF);
    mlx_loop(mlx);

	return (0);
}
//cc main.c -Imlx_linux -lXext -lX11 -lm -lz minilibx-linux/libmlx.a
// cc main.c -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz minilibx-linux/libmlx.a