/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   payer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:55:39 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/21 22:55:56 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'P')
			{
				game->player->x = x;
				game->player->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
