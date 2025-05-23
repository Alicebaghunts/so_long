/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-13 11:18:12 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-13 11:18:12 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_coin_and_exit(t_game *data, int x, int y)
{
	if (data->map->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background,
			x * TILE_SIZE, y * TILE_SIZE);
		data->map->map[y][x] = '0';
		data->map->coin--;
		return ;
	}
	if (data->map->map[y][x] == 'E' && data->map->coin == 0)
		close_game(data);
	if (data->map->map[y][x] == 'B')
		close_game(data);
}

void	call_move(int keycode, t_game *data)
{
	data->player->frame_rate = 0;
	if (data->player->x % TILE_SIZE != 0 || data->player->y % TILE_SIZE != 0)
		return ;
	if (keycode == W)
		handle_move_up(data);
	else if (keycode == S)
		handle_move_down(data);
	else if (keycode == A)
		handle_move_left(data);
	else if (keycode == D)
		handle_move_right(data);
}

void	show_moves(t_game *data)
{
	char	*count_str;
	char	*display_str;

	count_str = ft_itoa(data->moves);
	display_str = ft_strjoin("Moves: ", count_str);
	mlx_put_image_to_window(data->mlx, data->win, data->images->wall, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->images->wall, 64, 0);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, display_str);
	free(count_str);
	free(display_str);
}
