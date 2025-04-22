/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:46:23 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/21 23:09:08 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	fill_coin(char **map, int x, int y, int *coin_count)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		(*coin_count)++;
	map[y][x] = 'F';
	fill_coin(map, x + 1, y, coin_count);
	fill_coin(map, x - 1, y, coin_count);
	fill_coin(map, x, y + 1, coin_count);
	fill_coin(map, x, y - 1, coin_count);
}

char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}


int	has_minimum_two_coins(t_game *game)
{
	char	**copy;
	int		i;
	int		coin_count;

	copy = copy_map(&game->map);
	if (!copy)
		error_handling(MALLOC_ERROR);
	coin_count = 0;
	fill_coin(copy, game->player.x, game->player.y, &coin_count);
	i = 0;
	while (copy[i])
		free(copy[i++]);
	free(copy);
	return (coin_count >= 2);
}

void	fill_exit(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'F';
		return ;
	}
	map[y][x] = 'F';
	fill_exit(map, x + 1, y);
	fill_exit(map, x - 1, y);
	fill_exit(map, x, y + 1);
	fill_exit(map, x, y - 1);
}

int	is_exit_reachable(t_game *game)
{
	char	**copy;
	int		i;
	int		has_exit;

	copy = copy_map(&game->map);
	if (!copy)
		error_handling(MALLOC_ERROR);
	fill_exit(copy, game->player.x, game->player.y);
	has_exit = 0;
	i = 0;
	while (copy[i])
	{
		if (ft_strchr(copy[i], 'E'))
			has_exit = 1;
		free(copy[i++]);
	}
	free(copy);
	return (has_exit);
}
