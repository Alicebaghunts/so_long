/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:45:02 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/24 19:42:43 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int	checking_walls(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->map || !map->map[0])
		return (0);
	j = 0;
	while (j < map->width)
	{
		if (map->map[0][j] != '1'
			|| map->map[map->height - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (i < map->height - 1)
	{
		if (map->map[i][0] != '1'
			|| map->map[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	checking_exits(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->map || !map->map[0])
		return (0);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'E')
				map->exits++;
			j++;
		}
		i++;
	}
	if (map->exits != 1)
		return (0);
	return (1);
}

int	checking_coins(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->map || !map->map[0])
		return (0);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'C')
				map->coin++;
			j++;
		}
		i++;
	}
	if (map->coin < 2)
		return (0);
	return (1);
}

int	checking_position(t_map *map)
{
	int	i;
	int	j;
	int	pos;

	pos = 0;
	if (!map || !map->map || !map->map[0])
		return (0);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				pos++;
			j++;
		}
		i++;
	}
	if (pos != 1)
		return (0);
	return (1);
}

int	checking_all_characters(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->map || !map->map[0])
		return (0);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] != '0' && map->map[i][j] != '1'
				&& map->map[i][j] != 'C' && map->map[i][j] != 'E'
				&& map->map[i][j] != 'P' && map->map[i][j] != 'A')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
